/* ====================================
File name: exerc_4_5.c
Date: 2020-02-20
Group Number:
Members That contributed:
Erik Tingström
Lema Rassul
Susan Lieu
Members not present at the demonstration:
-----
Demonstration code: [45522]
====================================== */

unsigned char foundKey;
unsigned char pressedKey;
int foundRow;
int colPressed;

void setup(){
  Serial.begin(9600);
  DDRD = 0x00; // 0000 0000
  DDRB = 0xFF; // 1111 1111
  PORTB = 0xF7; // 1111 0111
}

void loop(){
  
  pressedKey = keyPressed();
  if (pressedKey != 0xFF){
    Serial.print(pressedKey, HEX);
    delay(1000);
  }
}

int getRow(){
  if (PORTB == 0XF7){
    return 0;
  } else if (PORTB == 0x7B){
    return 1;
  } else if (PORTB == 0x3D){
    return 2;
  } else if (PORTB == 0x1E){
    return 3;
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

unsigned char keyPressed(){
  
  if(PIND == 0xF3){
    
    if (PORTB == 0x1E){
      PORTB = 0xF7;
    } else {
      PORTB = PORTB >> 1;
    }
    return 0xFF;
    
  } else {
    
    foundRow = getRow();
    colPressed = getCol();
    foundKey = getKey(foundRow, colPressed);
    return foundKey;
    
  }
}