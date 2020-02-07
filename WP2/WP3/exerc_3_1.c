#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 30

enum DIRECTION {N,O,S,W};
void move(int *pPosX, int *pPos, enum DIRECTION *pDir);
void turn(enum DIRECTION *pDir);
void clear_stdin(void);

typedef struct {
int xpos;
int ypos;
enum DIRECTION dir;
} ROBOT;


void move(int *pPosX, int *pPosY, enum DIRECTION *pDir){
  if (*pDir == N){
    *pPosY += 1; 
  } else if(*pDir == O){
    *pPosX += 1;
  } else if(*pDir == S){
    *pPosY -= 1;
  } else if (*pDir == W){
    *pPosX -= 1;
  }
}

//void turn(char *c, int *pPosX, int *pPosY, enum DIRECTION *pDir){
void turn(enum DIRECTION *pDir){
  if (*pDir == N){
    *pDir = O;
  } else if (*pDir == O){
    *pDir = S;
  } else if(*pDir == S){
    *pDir = W;
  } else if (*pDir == W){
    *pDir = N;
  }
}

void clear_stdin(void){
  while(getchar() != '\n'){

  }
}

int main(){
  ROBOT robot;
  int i;
  char directionInput[MAX];
  int *pPosX = &robot.xpos;
  int *pPosY = &robot.ypos;
  char *pDirectionInput = directionInput;
  enum DIRECTION *pDir = &robot.dir;

  robot.dir = N;

  printf("%d\n", robot.dir);

  while (true) {
    puts("Enter x position:");
    scanf("%d", &robot.xpos);
    clear_stdin();
    while (robot.xpos < 0 || robot.xpos > 99){
      puts("Please enter a position between 0 and 99. Enter x position:");
      scanf("%d", &robot.xpos);
      clear_stdin();
    }
    puts("Enter y position:");
    scanf("%d", &robot.ypos);
    clear_stdin();
    while (robot.ypos < 0 || robot.ypos > 99){
      puts("Please enter a position between 0 and 99. Enter y position:");
      scanf("%d", &robot.ypos);
      clear_stdin();
    }
    printf("Enter directions (m & t): ");
    fgets(directionInput, MAX, stdin);

    for(i = 0; i < MAX; i++){
      if(directionInput[i] == 'm'){
        move(pPosX, pPosY, pDir);
        if(robot.xpos < 0 || robot.xpos > 99 || robot.ypos < 0 || robot.ypos > 99){
          break;
        }
      } else if (directionInput[i] == 't'){
        turn(pDir);
      }
    }
    if(robot.xpos < 0 || robot.xpos > 99 || robot.ypos < 0 || robot.ypos > 99){
      puts("Robot went out of bounds");
    } else {
      printf("Position of x: %d Position of y: %d\n", *pPosX, *pPosY);
    }
  }
  return 0;
}