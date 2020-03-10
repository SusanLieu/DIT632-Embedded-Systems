#include <stdio.h>
#include <string.h>

void encryptWord(char word[]){
  int i;
  char x;
  while (word[i] != '\0'){
    if (word[i] >= 'a' && word[i] <= 'm'){
      x = word[i] + 13;
      printf("%c", x);
    }
    if (word[i] >= 'n' && word[i] <= 'z'){
      x = word[i] - 13;
      printf("%c", x);
    }
    if (word[i] >= 'A' && word[i] <= 'M'){
      x = word[i] + 13;
      printf("%c", x);
    }
    if (word[i] >= 'N' && word[i] <= 'Z'){
      x = word[i] - 13;
      printf("%c", x);
    }
    if (word[i] == ' '){
      printf(" ");
    }
    i++;
  }
  printf("\n");
}

int main(void){
  int MAX = 50;
  char word[MAX];

  printf("Enter a word to be encrypted: ");
  while(fgets(word, MAX, stdin)){
    encryptWord(word);
  }
}