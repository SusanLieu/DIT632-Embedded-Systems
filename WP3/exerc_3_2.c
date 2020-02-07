#include <stdio.h>

int search_number(int number, int tab[], int size);
void sort (int number, int tab []);

void sort (int number, int tab[]){
  int i, j;
  int temp;
  int min;

  for (i = 0; i < number; i++){
    min = i;
    for (j = i; j < number; j++){
      if (tab[j] < tab[min]){
        min = j;
      }
    }
    // save min value in temp
    temp = tab[min];
    // place value of first position of this iternation in min's place
    tab[min] = tab[i];
    // place minimum value in first position
    tab[i] = temp;
  }

  for (i = 0; i < number; i++){
    printf("%d ", tab[i]);
  }
  printf("\n");
}

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
  int test [] = {1, 2, 34, 5, 67, 3, 23, 12, 12, 13, 10, 12, 21, 4};
  size = sizeof(test)/sizeof(test[0]);

  puts("Enter a number to search for: ");
  scanf("%d", &number);

  result = search_number(number, test, size);

  if (result == -1){
    puts("Number is not in array.");
  } else{
    printf("Number found in postion %d of the array.\n", result);
  }

  sort(size, test);
  return 0;
}