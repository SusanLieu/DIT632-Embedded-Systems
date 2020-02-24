#define ML13_Status 0x0B10     // READ 
#define read_control *((char *)ML13_Status)

#define ML13_Control 0x0B00    // WRITE
#define set_control(x) *((char *)ML13_Control) = x

#define DOOR_CLOSING 128
#define DOOR_OPENING 64
#define DOOR_CLOSED 32
#define DOOR_OPENED 16
#define DOOR_ACTIVATED 8

#define OPEN_DOOR 1
#define CLOSE_DOOR 2
#define CLEAR 0

void openDoor();
void keepDoorOpen();
void closeDoor();
void delay();

int main(void){
  
  unsigned char readStatus;
  while(1){
    readStatus = read_control;
    switch (readStatus){
      case (DOOR_ACTIVATED|DOOR_CLOSED):
        set_control(OPEN_DOOR);
        // call function to open door slowly (openDoor -> keepDoorOpen)
        // which that function then calls a keep door open function

        /*
        make another method with interrupts or something
        if set_control(OPEN_DOOR)? <-- something that recognises the change
        */

        openDoor();
        break;
      case (DOOR_ACTIVATED|DOOR_OPENED):
        // keep door open function?? (keepDoorOpen) to reset timer
        // keepDoorOpen function should set_control(CLOSE_DOOR) -> call another function to close door
        keepDoorOpen();
        break;
      case (DOOR_ACTIVATED|DOOR_OPENING):
        // do nothing
        break;
      case (DOOR_ACTIVATED|DOOR_CLOSING):
        set_control(OPEN_DOOR);
        openDoor();
        break;
    }
  }
}

void openDoor(){
  set_control(CLEAR);
  delay();
  keepDoorOpen();
}

void keepDoorOpen(){
  delay();
  set_control(CLOSE_DOOR);
  closeDoor();
}

void closeDoor(){
  set_control(CLEAR);
  delay();
}

void delay(){
  int i, j;
  for (i = 0; i < 60000; i++){
    for (j = 0; j < 60000; j++){
    }
  }
}