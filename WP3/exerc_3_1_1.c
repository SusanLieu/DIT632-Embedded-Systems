#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

enum DIRECTION {N,O,S,W};

typedef struct {
  int xpos;
  int ypos;
  enum DIRECTION dir;
} ROBOT;

void recordFirstPos(ROBOT *records, int *last);
void recordDirections(ROBOT *records, int *last);
void move(ROBOT *records);
void turn(ROBOT *records);
void turn();

void clear_stdin(void){
  while(getchar() != '\n'){
  }
}

void recordFirstPos(ROBOT *records, int *last){

  records->dir = N;

  puts("Enter x position: ");
  scanf("%d", &records->xpos);
  clear_stdin();
  while (records->xpos < 0 || records->xpos > 99){
    puts("Please enter a position between 0 and 99. Enter x position:");
    scanf("%d", &records->xpos);
    clear_stdin();
  }
  puts("Enter y position: ");
  scanf("%d", &records->ypos);
  clear_stdin();
  while (records->ypos < 0 || records->ypos > 99){
    puts("Please enter a position between 0 and 99. Enter y position:");
    scanf("%d", &records->ypos);
    clear_stdin();
  }
  *last = 0; 
}

void recordDirections(ROBOT *records, int *last){
  char directions[MAX];
  int len, i = 0;
  printf("Enter directions (m & t): ");
  fgets(directions, MAX, stdin);
  len = strlen(directions);
  while (i < len - 1){
    if (directions[i] == 'm'){
      move(records);
      records++;
      if(records->xpos < 0 || records->xpos > 99 || records->ypos < 0 || records->ypos > 99){
        i++;
        break;
      }
    } else if (directions[i] == 't'){
      turn(records);
      records++;
    } else {
      puts("Error: Another character other than m or t was entered.");
      break;
    }
    i++;
  }
  *last = i;
}

void move(ROBOT *records){
  int nextPosX, nextPosY, nextDir;

  if(records->dir == N){
    nextPosX = records->xpos;
    nextPosY = records->ypos + 1;
  } else if(records->dir == O){
    nextPosX = records->xpos + 1;
    nextPosY = records->ypos;
  } else if(records->dir == S){
    nextPosX = records->xpos;
    nextPosY = records->ypos - 1;
  } else if(records->dir == W){
    nextPosX = records->xpos - 1;
    nextPosY = records->ypos;
  }

  nextDir = records->dir;
  records++;
  records->xpos = nextPosX;
  records->ypos = nextPosY;
  records->dir = nextDir;
}

void turn(ROBOT *records){
  int nextPosX, nextPosY;
  int nextDir;
  int currentDir;

  nextPosX = records->xpos;
  nextPosY = records->ypos;
  currentDir = records->dir;
  records++;
  records->xpos = nextPosX;
  records->ypos = nextPosY;

  if(currentDir == N){
    records->dir = O;
  } else if(currentDir == O){
    records->dir = S;
  } else if(currentDir == S){
    records->dir = W;
  } else if(currentDir == W){
    records->dir = N;
  }
}

int main(){
  ROBOT records[MAX], lastRecord;
  ROBOT *pRecords = records;
  ROBOT *pLastRecord = &lastRecord;
  int last;
  int *pLast = &last;

  while(true){

    recordFirstPos(records, pLast);
    recordDirections(pRecords, pLast);

    *pLastRecord = records[last];
    printf("Last position: %d\n", last);
    if(pLastRecord->xpos < 0 || pLastRecord->xpos > 99 || pLastRecord->ypos < 0 || pLastRecord->ypos > 99){
      puts("Robot went out of bounds");
    } else {
      printf("Position of x: %d\nPosition of y: %d\n", pLastRecord->xpos, pLastRecord->ypos);
    }
  }
  return 0;
}