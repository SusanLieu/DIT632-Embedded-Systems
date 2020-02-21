unsigned char foundKey;
bool pressedKey = false;
int foundRow;
int colPressed;
int analogInput;

void setup(){
  Serial.begin(9600);
  DDRD = 0x00; // 0000 0000
  DDRB = 0xFF; // 1111 1111
  
  attachInterrupt (digitalPinToInterrupt(2), keyboardirq , FALLING);
}

void loop(){
  
  PORTB = 0x00;
  if (pressedKey){
    Serial.println(foundKey, HEX);
    pressedKey = false;
    //delay(1000);
  }
  
  analogInput = analogRead(A0);
  float returnedTemp = calculateTemp(analogInput);
  Serial.println(returnedTemp);
  delay(500);
}

float calculateTemp(int reading){
  float temp;
  
  //Convert the analog reading to voltage - 5v
  //"quantizing" the analog signal - 10bit resolution = 2^10 = 1024
  //analog reading gives us a value between 0 and 1023, 0 being no voltage and 1023 being 5V.
  //to convert voltage to degrees, we first find the percentage of 5v (1024) on the reading
  temp = (float)reading/1024;
  
  //convert percentage of reading to voltabe by multiply by 5v
  temp = temp * 5;
  
  // TMP36 has 500mV offset and 10mV/C degree scale
  // sensor's range is 175 degrees (-50° to 125°)
  // currently, this will show a meaurement of 0-175
  // substract -0.5 to set ranges from -50 to 125 where 0V = -50
  temp = temp - 0.5;
  
  //10 mV/ °C => convert from millivolts to degrees Celsius
  //1000mV=1V
  //Voltage is in Volts so multiply by 100 instead of divide by 10 to get correct result
  temp = temp * 100;
  
  return temp;
}

void keyboardirq(void){
  
  //iterate row PORTB, then check col PIND for each row
  for (int i = 0; i < 4; i++){
    if (i == 0){
      PORTB = B11110111;
    }else if (i == 1){
      PORTB = PORTB >> 1;
    } else if (i == 2){
      PORTB = PORTB >> 1;
    } else if (i == 3){
      PORTB = PORTB >> 1;
    }
    
    if ((PIND >> 4) != B00001111){
      foundRow = i;
      colPressed = getCol();
      foundKey = getKey(foundRow, colPressed);
      pressedKey = true;
    }
  }
}

int getCol(){
  if ((PIND >> 4) == 0x07){
    return 0;
  } else if ((PIND >> 4) == 0x0B){
    return 1;
  } else if ((PIND >> 4) == 0x0D){
    return 2;
  } else if ((PIND >> 4) == 0x0E){
    return 3;
  }
}

unsigned char getKey(int row, int col){
  unsigned char keys[4][4] = {
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {8, 9, 10, 11},
    {12, 13, 14, 15}
  };
  return keys[row][col];
}