#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define MAXNUMBER 20

// ------ Function declaration ----------
void create_random(int *tab); // Use pointer to fill the table
void count_frequency(int *tab, int *freq ); // Use pointer
void draw_histogram(int *freq ); // Use pointer

void create_random(int *tab){
  int i;
  srand(time(NULL));

  for (i = 0; i < MAX; i++){
    *(tab + i) = rand() % MAXNUMBER;
  }
}

void count_frequency(int *tab, int *freq){
  int i;
  for(i = 0; i < MAX; i++){
    printf("%d\n", *(tab + i));
  }
}

int main(void){
  int table[MAX], n;
  int frequency[MAXNUMBER];
  create_random(table);
  count_frequency(table, frequency);
}