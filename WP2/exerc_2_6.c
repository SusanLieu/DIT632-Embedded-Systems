/* ====================================

File name: exerc_2_6.c
Date: 2020-02-06
Group nr 5
Members that contribute to the solutions
Erik Tingström
Lema Rassul
Susan Lieu
Member not present at demonstration time:
Lema Rassul
Demonstration code: 35286

====================================== */

#include <stdio.h>

// compiler will translate int list[] to int *list
void initQue (int list[], int max){
  int i;
  for(i = 0; i < max; i++){
    list[i] = -1;
  }
}

// return 1 if the number could be entered and 0 if the queue is full
int input(int list[], int number, int max){
  int i = 0;

  while (list[i] != -1 && i < max){
    i++;
  }
  if(i < max){
    list[i] = number;
    return 1;
  } else {
    return 0;
  }
}

// returns the value if any to fetch or 0 if que is empty
int output(int list[], int max){
  int temp, i;
  if (list[0] != -1){
    temp = list[0];
    for(i = 0; i < max-1; i++){
      list[i] = list[i+1];
    }
    list[max-1] = -1;
    return temp;
  } else {
    return 0;
  }
}

void printArray(int list[], int max){
  int i;
  puts("The current queue: ");
  for(i = 0; i < max; i++){
    printf("%d ", list[i]);
  }
  puts("\n-----------------------------");
}

int main (){
  int max = 5, i, returnCode, outNum, size;
  int que[max];
  int testInputLong[] = {5, 10, 2, 3, 9, 8, 100};
  int testInputShort[] = {7, 1};

  initQue(que, max);

  printArray(que, max);

  outNum = output(que, max);
  puts("Fetching from queue..");
  printf("Output: %d\n", outNum);
  printArray(que, max);

  size = sizeof(testInputLong)/sizeof(testInputLong[0]);

  for (i = 0; i < size; i++){
    returnCode = input(que, testInputLong[i], max);
    printf("Adding %d to queue.\n", testInputLong[i]);
    printf("Return code: %d\n", returnCode);
    printArray(que, max);
  }

  for (i = 0; i < 3; i++){
    outNum = output(que, max);
    puts("Fetching from queue..");
    printf("Output: %d\n", outNum);
    printArray(que, max);
  }

  size = sizeof(testInputShort)/sizeof(testInputShort[0]);

  for (i = 0; i < size; i++){
    returnCode = input(que, testInputLong[i], max);
    printf("Adding %d to queue.\n", testInputLong[i]);
    printf("Return code: %d\n", returnCode);
    printArray(que, max);
  }
  return 0;
}