#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include "functions.h"

int generateNum(){
  srand(time(NULL));
  return rand() % 100;
}

void newRound(){
  char x[3];
  char str[] = "yes";
  printf("Would you like to play a new round? (yes/no)\n");
  scanf("%s", x);
  if (strncmp(x, str, 3) == 0){
    startGame();
  } else {
    printf("Thank you for playing.");
  }
}

void startGame(){
  int guess;
  int counter = 0;
  const int MAX_NUMBER = 20;
  int num = generateNum();

  printf("===== Welcome to guess the number =====\n");
  printf("Enter your guess: ");
  
  while(scanf("%d", &guess)){
    if (guess > num && counter < MAX_NUMBER) {
      counter++;
      printf("Your guess is too high. Try again: ");
    } else if (guess < num && counter < MAX_NUMBER){
      counter++;
      printf("Your guess is too low. Try again: ");
    } else if ((guess > num || guess < num) && counter >= MAX_NUMBER){
      printf("Number of guesses exceeded. ");
      newRound();
    } else if (guess == num){
      counter++;
      printf("You have guessed %d times and your guess is correct. ", counter);
      newRound();
    }
  }
}

// int guessNum(){
//   int guess;
//   printf("Enter your guess: ");
//   scanf("%d", &guess);
//   // Check if guess is an integer
//   return guess;
// }

int main(void){
  startGame();
}