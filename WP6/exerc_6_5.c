// Skeleton for exercise nr 5 in WP 6 course DIT632.
// File skeleton_exerc_6_5.c  
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>

pthread_mutex_t count_mutex     = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  not_empty   = PTHREAD_COND_INITIALIZER;
pthread_cond_t  not_full   = PTHREAD_COND_INITIALIZER;

// Global buffer and corresponding counters.
char  letter = 'a'; //the starting letter
#define MAX 10//buffer size

unsigned short count = 0;
char buffer[MAX]; // circular buffer
int inpos = 0; // index for next character to be put in buffer (put)
int outpos = 0; // index for next character to be read ( fetch )
bool fullBuffer = false;
//bool empty = true;

void *put();
void *fetch();

int main(){


  pthread_t producer, consumer;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_create(&producer, &attr, put, NULL);
  pthread_create(&consumer, &attr, fetch, NULL);
  int i;


    while(1){
      puts("\n Main is executing");
      for (i=0; i<20000; i++); 
    }

pthread_join(producer, NULL);
pthread_join(consumer, NULL);
return 0;
}


void *put(){
  int r, m;
    while(1){
      if ((r = pthread_mutex_lock(&count_mutex)) != 0){
        fprintf(stderr, "Error = %d (%s)\n", r, strerror(r));
        exit(1);
      }

      if(fullBuffer){
        pthread_cond_wait(&not_full, &count_mutex);
      }

      if (inpos < MAX){
        buffer[inpos] = letter;
        inpos++;
        letter++;
        puts("Buffer store");
        pthread_cond_signal(&not_empty);
      } else {
        inpos = 0;
      }
      

      if (letter > 'z'){
        letter = 'a';
      }
      
      if(inpos == outpos){
        fullBuffer = true;
        puts("Buffer is full");
      }

      if ((r = pthread_mutex_unlock(&count_mutex)) != 0) {
            fprintf (stderr, "Error = %d (%s)\n", r, strerror (r)); 
						exit (1);
        }

        for(m=0; m<1000; m++); // To delay a bit , give time for prod
    }
   
}


void *fetch(){
  int r, m;
    while(1){
      if ((r = pthread_mutex_lock(&count_mutex)) != 0){
        fprintf(stderr, "Error = %d (%s)\n", r, strerror(r));
        exit(1);
      }

      //if no char in buffer wait for below signal
      if(inpos == outpos && !fullBuffer){
        pthread_cond_wait(&not_empty, &count_mutex);
      }
      
      printf("Buffer output : %c\n", buffer[outpos]);
      outpos++;
      fullBuffer = false;
      pthread_cond_signal(&not_full);

      if(outpos == MAX){
        outpos = 0;
      }

      if ((r = pthread_mutex_unlock(&count_mutex)) != 0) {
            fprintf (stderr, "Error = %d (%s)\n", r, strerror (r)); 
						exit (1);
        }
      for(m=0; m<1000; m++); // To delay a bit , give time for prod.
    }

}
