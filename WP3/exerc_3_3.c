/********************************************
DIT1165 Program file exerc_3_3.c **
2018-01-04 **
********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Konstanter #####
#define MAX 5

// ##### Typedefs ####
typedef struct q{
  int number;
  struct q *next;
  struct q *prev;
} REGTYPE;

// ##### Funcion declarations #####
REGTYPE* random_list(void);
REGTYPE* add_first(REGTYPE *temp, int data);

//###### Main program #######
int main(int argc, char *argv[]){
  int nr = 0;
  REGTYPE *akt_post , *head = NULL;
  srand(time(0)); // Random seed
  head = random_list();
  head = add_first(head, 10);
  akt_post = head;

  while(akt_post != NULL){
    printf("Post nr %d : %d\n", nr++, akt_post->number);
    akt_post = akt_post->next;
  }

// --- Free of allocated memory ---
  while((akt_post = head) != NULL){
    head = akt_post->next;
    free(akt_post);
  }
//------------------

  return 0;
}
// ==== End of main ======================================


REGTYPE* random_list(void ){
  int nr = 5;
  int i = 0;
  REGTYPE *top, *old, *item;

  top = (REGTYPE*) malloc(sizeof(REGTYPE));
  top->number = rand() % 100;
  top->prev = NULL;
  top->next = NULL;
  item = top;

  for (i = 0; i < nr; i++){
    old = item;
    item = (REGTYPE*) malloc(sizeof(REGTYPE));
    item->number = rand() % 100;
    item->prev = old;
    item->next = NULL;
    old->next = item;
  }
  return(top);
}


//==========================================================
REGTYPE* add_first(REGTYPE* temp, int data){
  // Adds a record first i list and set the field tal to data
  REGTYPE *old, *item, *top;
  old = temp;
  temp = (REGTYPE*) malloc(sizeof(REGTYPE));
  temp->number = data;
  temp->prev = NULL;
  temp->next = old;
  old->prev = temp;
  top = temp;
  return (top);
}