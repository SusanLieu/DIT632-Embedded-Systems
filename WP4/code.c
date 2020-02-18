#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ( int argc, char *argv[]){
  unsigned char packedVar;
  int engine_on;
  int gear_pos;
  int key_pos;
  int brake1;
  int brake2;

  if (argc != 6){
    puts("Must input exactly 5 arguments/variables");
  } else {
    engine_on = atoi(argv[1]);
    gear_pos = atoi(argv[2]);
    key_pos = atoi(argv[3]);
    brake1 = atoi(argv[4]);
    brake2 = atoi(argv[5]);

    if (engine_on != 0 && engine_on != 1){
      puts("Invalid input.");
      exit(1);
    }
    if (gear_pos < 0 || gear_pos > 4){
      puts("Invalid input.");
      exit(1);
    }
    if (key_pos < 0 || key_pos > 2){
      puts("Invalid input.");
      exit(1);
    }
    if (brake1 != 0 && brake1 != 1) {
      puts("Invalid input.");
      exit(1);
    }
    if (brake2 != 0 && brake2 != 1) {
      puts("Invalid input.");
      exit(1);
    }
     
    packedVar = brake2;
    packedVar = packedVar | (brake1 << 1);
    packedVar = packedVar | (key_pos << 2);
    packedVar = packedVar | (gear_pos << 4);
    packedVar = packedVar | (engine_on << 7);
    
    /* This does the same thing as the one above
    packedVar = engine_on;
    packedVar = (packedVar << 3) + gear_pos;
    packedVar = (packedVar << 2) + key_pos;
    packedVar = (packedVar << 1) + brake1;
    packedVar = (packedVar << 1) + brake2;
    */

    printf("%x\n", packedVar);
    printf("%d\n", packedVar);
  }
}