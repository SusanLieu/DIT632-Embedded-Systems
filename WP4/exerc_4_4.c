// ---- Program template for Arduino in Tinkercad VT 2020
#include <avr/io.h>
#include <util/delay.h>
 
/* --- Macros preedefind for the compiler
DDRB  Data direction register B
PORTB Outport B
PINB  Inport B
DDRD  Data direction register D
PORTD Outport D
PIND  Inport D
*/

unsigned char input;

void setup() {
  
  DDRD = 0xFF; // 1111 1111
  DDRB = 0x00; // 0000 0000
  PORTD = 0x03; // 0000 0011
  delay(500);
}

void loop() {
  if(PINB == 1){
    if (PORTD == 0xc0){ // 0xc0 is binary 11000000
      PORTD = PORTD ^ 0x41; // 0x41 is binary 01000001;
    } else if (PORTD == 0x81){ // 0x81 is binary 10000001
      PORTD = PORTD ^ 0x82; // 0x82 is binary 10000010;
      //PORTD = B00000011;
    } else {
      PORTD = PORTD << 1;
    }
    delay(500);
  }
}