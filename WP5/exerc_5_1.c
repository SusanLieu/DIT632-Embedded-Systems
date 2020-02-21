/*-----------------------------------
- configure the IO ports
- in an infinity loop
Call a function checking if any key is pressed and if it
should return it´s value.
If a key was pressed print out the key value ( 0-9 ,
A-F) on the serial monitor.
Delay for one second.
-----------------------------------*/

/* --- Macros predefined for the compiler
DDRB Data direction register B
PORTB Outport B
PINB Inport B
DDRD Data direction register D
PORTD Outport D
PIND Inport D
*/

unsigned char foundKey;
bool pressedKey = false;
int foundRow;
int colPressed;

void setup(){
  Serial.begin(9600);
  DDRD = 0x00; // 0000 0000
  DDRB = 0xFF; // 1111 1111
  
  attachInterrupt (digitalPinToInterrupt(2), keyboardirq , FALLING);
}

void loop(){
  
  PORTB = 0x00;
  if (pressedKey){
    Serial.print(foundKey, HEX);
    pressedKey = false;
    delay(1000);
  }
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