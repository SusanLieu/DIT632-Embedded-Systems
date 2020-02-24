#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>

int program_time = 0; // The global time, start value 0
double get_time_ms();
void *time_count();
void *read_inport();

int main(){

  double time, oneSecond;

  pthread_t tid1, tid2;
  pthread_attr_t attr;
  pthread_attr_init(&attr);

  // Start up the thread time_count.
  pthread_create(&tid1, &attr, time_count, NULL);

  // Start up the thread read_inport.
  pthread_create(&tid2, &attr, read_inport, NULL);

  oneSecond = get_time_ms() + 1000;
  while (program_time < 50){
    time = get_time_ms();
    if (time >= oneSecond){
      //Print out system time every second.
      printf("System time: %f\n", time);
      oneSecond = time + 1000;
    }
  }
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
}
// --- End of main thread ------


// ----- Tread functions –----
//--------------------------------------------
void *time_count() {
  double time, oneSecond;

  oneSecond = get_time_ms() + 1000;
  while ( program_time < 50){
    // Check system-time ( get_time_ms())
    time = get_time_ms();
    if (time >= oneSecond){
      // Increase program_time by one every second.
      program_time++;
      oneSecond = time + 1000;
    }
  }
  // exit thread;
  pthread_exit(0);
} //End------------------------------------

void *read_inport(){
bool read = false;
  while (program_time < 50){
    // Read Inport every 5 second.
    if(program_time == 0){
      //do nothing
    } else if(program_time % 5 == 0){
      if (!read){
        //(Simulate this just by print out a text : Reading Inport now)
        puts("Reading Inport now");
        read = true;
      }
    } else {
      read = false;
    }
  }
  //Exit thread
  pthread_exit(0);
} //End------------------------------------


// -------- Function get_time_ms --------------------
double get_time_ms(){
struct timeval t;
gettimeofday(&t, NULL);
return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
} // ------------ End -------------------