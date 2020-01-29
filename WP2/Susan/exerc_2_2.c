#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main(void){
  int array[MAX];
  int i, j;
  int *p;
  srand(time(NULL));

  for (i = 0; i < MAX; i++){
    array[i] = rand() % 99 + 1;
  }

  p = array;
  
  printf("address of array: %p\n", p);
  printf("Address of array: %p\n", &array);
  printf("first int in array: %d\n", *p);
  printf("second int in array: %d\n", *(p + 1));
  printf("size of integer: %lu\n", sizeof(*p));
  printf("size of whole array: %lu\n", sizeof(array));

  puts("========================================");

  for (i = 0; i < MAX; i++){
    printf("integer value: %i\n", p[i]);
    printf("double value: %d\n", p[i]);
  }
  
}