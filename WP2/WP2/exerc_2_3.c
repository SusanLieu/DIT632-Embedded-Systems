/* ====================================

File name: exerc_2_3.c
Date: 2020-02-06
Group nr 5
Members that contribute to the solutions
Erik Tingström
Lema Rassul
Susan Lieu
Member not present at demonstration time:
Lema Rassul
Demonstration code: 31120

====================================== */

#include <stdio.h>
#include <string.h>
#define MAX 20

void isSameString(char first[], char second[]){
  if(strcmp(first, second) == 0){
    puts("These are identical strings - using strcmp");
    } else {
      puts("These are not identical strings - using strcmp");
    }
}

void isSameStringManual(char first[], char second[]){
  int length1, length2, i = 0;

  length1 = strlen(first);
  length2 = strlen(second);

  if(length1 == length2){
    while(first[i] == second[i] && first[i] != '\0'){
      i++;
    }
    if (i == length1){
      puts("These are identical strings - manual");
    } else {
      puts("These are not identical strings - manual");
    }
  } else {
    puts("These are not identical strings - manual");
  }
}

int main(int argc, char *argv[]){
  char first[MAX], second[MAX];

  if (argc == 3){
    strcpy(first, argv[1]);
    strcpy(second, argv[2]);

    isSameString(first, second);
    isSameStringManual(first, second);
  } else {
    puts("You did not enter exactly 2 strings");
  }
  return 0;
}