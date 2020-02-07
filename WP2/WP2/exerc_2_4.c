/* ====================================

File name: exerc_2_4.c
Date: 2020-02-06
Group nr 5
Members that contribute to the solutions
Erik Tingström
Lema Rassul
Susan Lieu
Member not present at demonstration time:
Lema Rassul
Demonstration code: 31251

====================================== */

#include <stdio.h> 
#include <string.h> 
#define MAX 20

int main(int argc, char *argv[]){
  char text[MAX], reversedText[MAX];
  int i, j, length;
  if (argc == 2){
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
  return 0;
}