/*

Enter header stuff maybe

*/

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
  puts("Copied text manually: ");
  puts(copiedText);
}

int main(void){
  char text[MAX];

  //read up on memset in optional reading in canvas and gdb debugging

  puts("Enter a string: ");
  fgets(text, MAX, stdin);
  copyStringUsingStrcpy(text);
  copyString(text);
}