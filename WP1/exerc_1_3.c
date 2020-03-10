#include <stdio.h>
#include <string.h>

void encryptWord(char word[]){
  char encrypted_str[50];
  char letter;
  char encryptionCode[] = "abcdefghijklmnopqrstuvwxyz";
  char encryptionCodeUpper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int length = strlen(word);
  printf("%i", length);
  for (int i = 0; word[i] != '\0'; i++){
    for (int j = 0; j < length; j++){
      if (word[i] == encryptionCode[j]){
        if (word[i] >= 'a' && word[i] <= 'm'){
          letter = encryptionCode[j + 13];
          printf("%c", letter);
        } else if (word[i] >= 'n' && word[i] <= 'z'){
          letter = encryptionCode[j - 13];
          printf("%c", letter);
        }
      }
      if (word[i] == encryptionCodeUpper[j]){
        if (word[i] >= 'A' && word[i] <= 'M'){
          letter = encryptionCodeUpper[j + 13];
          printf("%c", letter);
        } else if (word[i] >= 'N' && word[i] <= 'Z'){
          letter = encryptionCodeUpper[j - 13];
          printf("%c", letter);
        }
      }
    }
  }
  //printf("Encryped word: %s", encrypted_str);
}

int main(void){

  char str[50];

  printf("Enter a word to encrypt: ");
  scanf("%s", str);
  printf("Word entered: %s\n", str);
  encryptWord(str);
}