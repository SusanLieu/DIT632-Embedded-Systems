#include <stdio.h>

int search_number(int number, int tab[], int size);

int search_number(int number, int tab[], int size){
  int i;
  int result;
  for(i = 0; i < size; i++){
    if (tab[i] == number){
      result = i;
      break;
    } else {
      result = -1;
    }
  }
  return result;
}

int main(){
  int number;
  int size;
  int result;
  int test [] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10, 12, 21};
  size = sizeof(test)/sizeof(test[0]);
  puts("Enter a number to search for: ");
  scanf("%d", &number);
  result = search_number(number, test, size);
  if (result == -1){
    puts("Number is not in array.");
  } else{
    printf("Number found in postion %d of the array.\n", result);
  }
  return 0;
}