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

void recordFirstPos(ROBOT records[], int *last);
void recordDirections(ROBOT records[], int *last);
void move(int structPos, ROBOT records[]);
void turn(int structPos, ROBOT records[]);
void turn();

void clear_stdin(void){
  while(getchar() != '\n'){
  }
}

void recordFirstPos(ROBOT records[], int *last){

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

void recordDirections(ROBOT records[], int *last){
  char directions[MAX];
  int len, i = 0;
  printf("Enter directions (m & t): ");
  fgets(directions, MAX, stdin);
  len = strlen(directions);
  while (i < len){
    if (directions[i] == 'm'){
      move(i, records);
    } else if (directions[i] == 't'){
      turn(i, records);
    }
    i++;
  }
  *last = i - 1;
}

void move(int structPos, ROBOT records[]){
  int nextPosX, nextPosY, nextDir;
  if(records[structPos].dir == N){
    records[structPos + 1].xpos = records[structPos].xpos;
    records[structPos + 1].ypos = records[structPos].ypos + 1;
    records[structPos + 1].dir = records[structPos].dir;
  } else if(records[structPos].dir == O){
    records[structPos + 1].xpos = records[structPos].xpos + 1;
    records[structPos + 1].ypos = records[structPos].ypos;
    records[structPos + 1].dir = records[structPos].dir;
  } else if(records[structPos].dir == S){
    records[structPos + 1].xpos = records[structPos].xpos;
    records[structPos + 1].ypos = records[structPos].ypos - 1;
    records[structPos + 1].dir = records[structPos].dir;
  } else if(records[structPos].dir == W){
    records[structPos + 1].xpos = records[structPos].xpos - 1;
    records[structPos + 1].ypos = records[structPos].ypos;
    records[structPos + 1].dir = records[structPos].dir;
  }
}

void turn(int structPos, ROBOT records[]){
  records[structPos + 1].xpos = records[structPos].xpos;
  records[structPos + 1].ypos = records[structPos].ypos;
  if(records[structPos].dir == N){
    records[structPos + 1].dir = O;
  } else if(records[structPos].dir == O){
    records[structPos + 1].dir = S;
  } else if(records[structPos].dir == S){
    records[structPos + 1].dir = W;
  } else if(records[structPos].dir == W){
    records[structPos + 1].dir = N;
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
    printf("Position of x: %d\nPosition of y: %d\n", pLastRecord->xpos, pLastRecord->ypos);
    
  }
  return 0;
}