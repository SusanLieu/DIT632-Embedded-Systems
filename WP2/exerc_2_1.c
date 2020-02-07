/* ====================================

File name: exerc_2_1.c
Date: 2020-02-06
Group nr 5
Members that contribute to the solutions
Erik Tingström
Lema Rassul
Susan Lieu
Member not present at demonstration time:
Lema Rassul
Demonstration code: 36068

====================================== */

#include <stdio.h>
#include <string.h>
#define MAX 20

void copyStringUsingStrcpy(char text[]){
  char copiedText[MAX];
  strcpy(copiedText, text);
  printf("Copied text using strcpy: %s", copiedText);
}

void copyString(char text[]){
  int i = 0;
  char copiedText[MAX];
  while(text[i] != '\0'){
    copiedText[i] = text[i];
    i++;
  }
  printf("Copied text manually: %s\n", copiedText);
}

int main(){
  char text[MAX];

  puts("Enter a string: ");
  fgets(text, MAX, stdin);
  copyStringUsingStrcpy(text);
  copyString(text);
  return 0;
}