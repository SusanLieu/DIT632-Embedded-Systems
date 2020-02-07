/* ====================================

File name: exerc_2_5.c
Date: 2020-02-06
Group nr 5
Members that contribute to the solutions
Erik Tingström
Lema Rassul
Susan Lieu
Member not present at demonstration time:
Lema Rassul
Demonstration code: 32005

====================================== */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define MAXNUMBER 20

// could use int tab[] instead of int *tab
// compiler will translate int tab[] to int *tab for arrays
void create_random(int *tab){
  int i;
  srand(time(NULL));

  for (i = 0; i < MAX; i++){
    *(tab + i) = rand() % MAXNUMBER;
    //printf("%d\n", *(tab + i));
  }
}

void count_frequency(int *tab, int *freq){
  int i;
  for(i = 0; i < MAX; i++){
    *(freq + *(tab + i)) += 1;
    // freq[tab[i]] += 1;
  }
}

void draw_histogram(int *freq){
  int i, j;
  char x = 'x';
  for(i = 0; i < MAXNUMBER; i++){
    if (*(freq + i) != 0){
      printf("%d ", i);
      for(j = 0; j < *(freq + i); j++){
        printf("%c", x);
      }
      printf("\n");
    }
  }
}

int main(){
  int table[MAX], n;
  int frequency[MAXNUMBER] = {0};
  int *pTable = table;
  create_random(pTable);
  count_frequency(table, frequency);
  draw_histogram(frequency);
  return 0;
}