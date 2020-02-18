#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void f_delay(int);
unsigned char random_inport( void);

int main(){
	int nr;
  unsigned char notPressed = 0x8F;
	unsigned char port;
	srand(time(0)); 
  
	while (1) {
	   port = random_inport();
		 if ((notPressed & port) >> 7 == 0){
			 printf("Hexadecimal form of pressed key (%d): %x\n", port, port);
		 }
	   f_delay(5);
  }
	return(0);
}

void f_delay(int tenth_sec){

   clock_t start_t, end_t;
   long int i;
   start_t = clock();
   do{
      for(i=0; i< 10000000; i++);
      end_t = clock();
   }while ((end_t - start_t) < (tenth_sec*CLOCKS_PER_SEC)/10);
   return;
}

unsigned char random_inport( void){
	unsigned char inport = 0;
	inport = rand() % 16;
	return (inport);
}