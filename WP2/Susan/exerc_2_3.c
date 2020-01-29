#include <stdio.h>
#include <string.h>
#define MAX 20

void isSameString(char first[], char second[]){
  if(strcmp(first, second) == 0){
    puts("Tis the same");
    } else {
      puts("Not the same strcmp");
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
      puts("The same");
    } else {
      puts("Not the same manually");
    }
  } else {
    puts("Not the same");
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
}