#include <stdio.h>
#include <string.h>

int countWords(char sentence[]){
  int count = 0;
  int length = strlen(sentence);
  for (int i = 0; sentence[i] != '\0'; i++){
    if (sentence[i] == ' '){
      count++;
    }
  }
  return count + 1;
}


int main(void){
  int MAX = 50;
  char a[MAX];
  int words;

  printf("Enter a sentence with MAX %i characters: ", MAX);
  fgets(a, MAX, stdin);
  words = countWords(a);
  printf("%d\n", words);
}