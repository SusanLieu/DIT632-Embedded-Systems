/* ====================================

File name: exerc_2_2.c
Date: 2020-02-06
Group nr 5
Members that contribute to the solutions
Erik Tingström
Lema Rassul
Susan Lieu
Member not present at demonstration time:
Lema Rassul
Demonstration code: 30634

====================================== */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main(){
  int array[MAX];
  int i, j;
  int *p = array;
  srand(time(NULL));

  for (i = 0; i < MAX; i++){
    array[i] = rand() % 99 + 1;
  }
  
  printf("The value of the label array (address) is: %p\n", p);
  printf("First integer in the array is (array[0]): %d\n", *p);
  printf("Second integer in the array is (array[1]): %d\n", *(p + 1));
  printf("The size of an integer (number of bytes) is: %lu\n", sizeof(*p));
  printf("The size of the whole array is: %lu\n", sizeof(array));

  puts("========================================");

  for (i = 0; i < MAX; i++){
    printf("Integer value: %i  Double value: %.1f\n", *(p + i), (double)*(p + i));
  }
  return 0;
}