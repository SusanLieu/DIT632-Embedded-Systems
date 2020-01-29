#include <stdio.h> 
#include <string.h> 
#define MAX 20

int main(int argc, char *argv[]){
  char text[MAX], reversedText[MAX];
  int i, j, length;
  strcpy(text, argv[1]);

  length = strlen(text);

  for (i = 0, j = length - 1; i < length; i++, j--){
    reversedText[i] = text[j];
  }
  
  if (strcmp(text, reversedText) == 0){
    puts("This word is a palindrome.");
  } else {
    puts("This word is not a palindrome.");
  }
}