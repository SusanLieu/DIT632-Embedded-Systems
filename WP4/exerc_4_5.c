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

unsigned char colPressed;
unsigned char key;
unsigned char foundKey;
unsigned char pressedKey;

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


unsigned char keyPressed(){
  
  if(PIND == 0xF3){
    
    if (PORTB == 0x1E){
      PORTB = 0xF7;
    } else {
      PORTB = PORTB >> 1;
    }
    
    return 0xFF;
    
  } else {
    
    colPressed = PIND; 
    /*
    if 2nd ROW was being checked when key pressed
    PORTB = 0111 1011
    PORTB << 4 would then be 1011 0000

    if 1st COL was pressed 
    PIND = 0111 0011 (natural num: 115)
    colPressed = PIND
    colKey >> 4 would then be 0000 0111

    Using the OR operator
    1011 0000
    0000 0111
    gives 1011 0111 => 0xB7 => key 4
    */
    key = (PORTB << 4)|(colPressed >> 4);
    
    if (key == 0x77){
      foundKey = 0;
    } else if (key == 0x7B){
      foundKey = 1;
    } else if (key == 0x7D){
      foundKey = 2;
    } else if (key == 0x7E){
      foundKey = 3;
    } else if (key == 0xB7){
      foundKey = 4;
    } else if (key == 0xBB){
      foundKey = 5;
    } else if (key == 0xBD){
      foundKey = 6;
    } else if (key == 0xBE){
      foundKey = 7;
    } else if (key == 0xD7){
      foundKey = 8;
    } else if (key == 0xDB){
      foundKey = 9;
    } else if (key == 0xDD){
      foundKey = 10;
    } else if (key == 0xDE){
      foundKey = 11;
    } else if (key == 0xE7){
      foundKey = 12;
    } else if (key == 0xEB){
      foundKey = 13;
    } else if (key == 0xED){
      foundKey = 14;
    } else if (key == 0xEE){
      foundKey = 15;
    }
    return foundKey;
  }
}