#include <stdio.h>
#include <stdlib.h>

int generateNum(){
  return rand() % 100;
}

int guessNum(){
  int guess;
  printf("Enter your guess: ");
  scanf("%d", &guess);
  // Check if guess is an integer
  return guess;
}

void printOptions(int i){
  switch(i){
    case 1:
      printf("Your guess is too high. Try again");
      guessNum();
      break;
  }
}

void startGame(){
  int guess;
  int counter;
  const int MAX_NUMBER = 20;
  int num = generateNum();

  printf("===== Welcome to guess the number =====\n");
  guess = guessNum();

  if (guess > num && counter < MAX_NUMBER) {
    counter++;
    printOptions(1);
  }
  if (guess < num && counter < MAX_NUMBER){
    counter++;
    printOptions(2);
  }
  if ((guess > num || guess < num) && counter >= MAX_NUMBER){
    printOptions(3);
  }
  if (guess == num){
    printOptions(4);
  }
}

int main(void){
  startGame();
}