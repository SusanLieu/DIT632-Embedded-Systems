#include <stdio.h>


  void printSentence(int i) {
    switch(i){
        case 1:
            printf("You chose sentence 1\n");
            break;
        case 2:
            printf("Sentence 2\n");
            break;
        case 3:
            printf("Sentence 3\n");
            break;
        case 4:
            printf("Sentence 4\n");
            break;
        case 5:
            printf("Sentence 5\n");
            break;
    }
  }

  int enterNum(){
    int i;
    printf("Enter a number between 1 and 5: ");
    scanf("%d", &i);
    return i;
  }

  int main(void) {
    int i;
    i = enterNum();

    while (i<6 && i>0){
      printSentence(i);
      i = enterNum();
    }
    return 0;
  }
