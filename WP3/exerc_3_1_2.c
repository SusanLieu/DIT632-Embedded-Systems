#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

enum DIRECTION {N,O,S,W};

typedef struct {
int xpos;
int ypos;
enum DIRECTION dir;
} ROBOT;

void init_robot(ROBOT *robot);
void move(ROBOT *robot);
void turn(ROBOT *robot);
void clear_stdin(void);

void init_robot(ROBOT *robot){

  robot->dir = N;

  puts("Enter x position:");
  scanf("%d", &robot->xpos);
  clear_stdin();
  while (robot->xpos < 0 || robot->xpos > 99){
    puts("Please enter a position between 0 and 99. Enter x position:");
    scanf("%d", &robot->xpos);
    clear_stdin();
  }
  puts("Enter y position:");
  scanf("%d", &robot->ypos);
  clear_stdin();
  while (robot->ypos < 0 || robot->ypos > 99){
    puts("Please enter a position between 0 and 99. Enter y position:");
    scanf("%d", &robot->ypos);
    clear_stdin();
  }
}

void move(ROBOT *robot){
  if (robot->dir == N){
    robot->ypos++; 
  } else if(robot->dir == O){
    robot->xpos++;
  } else if(robot->dir == S){
    robot->ypos--;
  } else if (robot->dir == W){
    robot->xpos--;
  }
}

void turn(ROBOT *robot){
  if (robot->dir == N){
    robot->dir = O;
  } else if (robot->dir == O){
    robot->dir = S;
  } else if(robot->dir == S){
    robot->dir = W;
  } else if (robot->dir == W){
    robot->dir = N;
  }
}

void clear_stdin(void){
  while(getchar() != '\n'){
  }
}

int main(){
  ROBOT *robot;
  int i, len;
  char directions[MAX];

  while (true) {

    init_robot(robot);

    printf("Enter directions (m & t): ");
    fgets(directions, MAX, stdin);
    len = strlen(directions);

    for(i = 0; i < len - 1; i++){
      if(directions[i] == 'm'){
        move(robot);
      } else if (directions[i] == 't'){
        turn(robot);
      } else {
        puts("Error: A character other than m or t was entered.");
        break;
      }
      if(robot->xpos < 0 || robot->xpos > 99 || robot->ypos < 0 || robot->ypos > 99){
        break;
      }
    }

    if(robot->xpos < 0 || robot->xpos > 99 || robot->ypos < 0 || robot->ypos > 99){
      puts("Robot went out of bounds");
    } else {
      printf("Position of x: %d\nPosition of y: %d\n", robot->xpos, robot->ypos);
      if (robot->dir == N){
        puts("Facing: North");
      } else if (robot->dir == O){
        puts("Facing: East");
      } else if (robot->dir == S){
        puts("Facing: South");
      } else {
        puts("Facing: West");
      }
    }
  }
  return 0;
}