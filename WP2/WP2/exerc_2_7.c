/* ====================================

File name: exerc_2_7.c
Date: 2020-02-06
Group nr 5
Members that contribute to the solutions
Erik Tingström
Lema Rassul
Susan Lieu
Member not present at demonstration time:
Lema Rassul
Demonstration code: 31370

====================================== */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

void readPersnr(char *person);
int controlDigit(const char *persnr);
bool isInRange(int *year, int *month, int*day);
unsigned concatenate(unsigned x, unsigned y);
void deconstruct(int *temp, int *numArray, int *size);
void clear_stdin(void);


void readPersnr(char *person){
  int temp[MAX], i, year, month, day;
  int *pYear = &year;
  int *pMonth = &month;
  int *pDay = &day;

  while (strcmp(person, "q") != 0){

    for (i = 0; i < MAX; i++){
      temp[i] = person[i] - 48;
    }

    year = concatenate(temp[0], temp[1]);
    month = concatenate(temp[2], temp[3]);
    day = concatenate(temp[4], temp[5]);

    if(isInRange(pYear, pMonth, pDay)){
      controlDigit(person);
    } else {
      puts("Incorrect month or day.");
    }

    puts("Enter personnummer to check (yymmddxxxx): ");
    scanf("%s", person);
    clear_stdin();
  }
  
}

unsigned concatenate(unsigned x, unsigned y) {
    unsigned pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;        
}

bool isInRange(int *year, int *month, int *day){
  if(*month <= 12 && *day <=31){
    if ((*month == 4 || *month == 6 || *month == 9 || *month == 11) && *day > 30){
      return false;
    } else if (*month == 2 && *year % 4 == 0 && *day > 29){
      return false;
    } else if (*month == 2 && *year % 4 != 0 && *day > 28){
      return false;
    } else {
      return true;
    }
  } else {
    return false;
  }
}

int controlDigit(const char *persnr){
  int i, x = 0;
  int controlInput, controlCalc, size, total = 0;
  int individualNum[14], temp[MAX];
  int *pSize = &size;

  for (i = 0; i < MAX - 1; i++){
      temp[i] = persnr[i] - 48;
    }
  
  controlInput = persnr[MAX - 1] - 48;
  deconstruct(temp, individualNum, pSize);

  for (i = 0; i < size; i++){
    total += individualNum[i];
  }

  controlCalc = (10 - (total % 10)) % 10;

  if(controlCalc == controlInput){
    puts("Valid personnummer entered!");
  } else {
    puts("Invalid personnummer entered ):");
  }
  return 0;
}

void deconstruct(int *temp, int *numArray, int *size){
  int i, j = 0, doubleNum;

  for (i = 0; i < MAX - 1; i++){
    if (i % 2 == 0){
      doubleNum = temp[i] * 2;
      if (doubleNum > 9){
        numArray[j] = doubleNum/10;
        j++;
        numArray[j] = doubleNum % 10;
        j++;
      } else {
        numArray[j] = doubleNum;
        j++;
      }
    } else {
      numArray[j] = temp[i];
      j++;
    }
  }

  *size = j;
}

void clear_stdin(void){
  while (getchar() != '\n'){

  }
}

int main(){
  char person[MAX];
  
  puts("Enter personnummer to check (yymmddxxxx): ");
  scanf("%s", person);
  clear_stdin();
  readPersnr(person);
  return 0;
}