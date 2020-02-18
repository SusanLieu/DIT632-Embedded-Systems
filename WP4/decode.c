#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  unsigned char input;
  unsigned char engine_on;
  unsigned char gear_pos;
  unsigned char key_pos;
  unsigned char brake1;
  unsigned char brake2;

  if (argc != 2){
    puts("Must input exactly 1 argument");
  } else {
    // strtol converts string to long integer, base 16 => Lecture 1_C_Intro, slide 10
    input = strtol(argv[1], NULL, 16);

    // 0b is the prefix for binary, similar to how 0x is for hexadecimal
    engine_on = (input & 0b10000000) >> 7;
    gear_pos = (input & 0b01110000) >> 4;
    key_pos = (input & 0b00001100) >> 2;
    brake1 = (input & 0b00000010) >> 1;
    brake2 = (input & 0b00000001);

    puts("\nName\t\tValue");
    puts("-----------------------");
    printf("engine_on\t%d\n", engine_on);
    printf("gear_pos\t%d\n", gear_pos);
    printf("key_pos\t\t%d\n", key_pos);
    printf("brake1\t\t%d\n", brake1);
    printf("brake2\t\t%d\n\n", brake2);
  }
}