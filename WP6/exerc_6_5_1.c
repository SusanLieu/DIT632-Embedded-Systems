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
      //pthread_mutex_lock(&count_mutex);
      if (count == 2){
        puts("\n Main is executing");
        //pthread_mutex_unlock(&count_mutex);
        count = 0;
      }
      /*for (i=0; i<1000; i++){
        for (int h = 0; h < 30000; h++);
      }*/
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
      if (count == 0){
        // if buffer is full, this will be set in a queue to wait for a signal that it's not full.
        if(fullBuffer){
          pthread_cond_wait(&not_full, &count_mutex);
        }

        if (inpos < MAX){
          buffer[inpos] = letter;
          printf("Buffer STORE letter %c at pos %d\n", letter, inpos);
          inpos++;
          letter++;
          pthread_cond_signal(&not_empty);
          count++;
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
      //count++;
      }

      if ((r = pthread_mutex_unlock(&count_mutex)) != 0) {
            fprintf (stderr, "Error = %d (%s)\n", r, strerror (r)); 
						exit (1);
        }

        /*for(m=0; m<1000; m++){
          for (int h = 0; h < 30000; h++);
        } // To delay a bit , give time for prod*/
    }
}


void *fetch(){
  int r, m;
    while(1){
      if ((r = pthread_mutex_lock(&count_mutex)) != 0){
        fprintf(stderr, "Error = %d (%s)\n", r, strerror(r));
        exit(1);
      }

        if(count == 1){
        //if no char in buffer wait for below signal
        if(inpos == outpos && !fullBuffer){
          pthread_cond_wait(&not_empty, &count_mutex);
        }

        if(outpos < MAX){
          printf("Buffer OUTPUT letter %c at pos %d\n", buffer[outpos], outpos);
          outpos++;
          fullBuffer = false;
          // to signal to the producer (put method) that the buffer is not full
          pthread_cond_signal(&not_full);
          count++;
        } else {
          outpos = 0;
        }
      //count++;
      }

      if ((r = pthread_mutex_unlock(&count_mutex)) != 0) {
            fprintf (stderr, "Error = %d (%s)\n", r, strerror (r)); 
						exit (1);
        }
      /*for(m=0; m<1000; m++){
        for (int h = 0; h < 30000; h++);
      } // To delay a bit , give time for prod.*/
    }

}
