/* ====================================

File name: exerc_2_8.c
Date: 2020-02-06
Group nr 5
Members that contribute to the solutions
Erik Tingström
Lema Rassul
Susan Lieu
Member not present at demonstration time:
Lema Rassul
Demonstration code: 33503

====================================== */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>    
#include<ctype.h> 


#define MAX_COINS 13

const int HUMAN = 0;
const int COMPUTER = 1;

/* ------------- IO --------------- */

/*
 * human_choice
 * Get human choce as an int from stdin.
 * Clears stdin.
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int human_choice(int pile);

/*
 * write_winner
 * Write winner as a string on stdout.
 * in: Values HUMAN or COMPUTER.
 * out:
 */
void write_winner( int player );

/*
 * play_again
 * Ask human if he/she wants to play
 * another round. If 'n' or 'N' selected
 * (single char) return false else true.
 * Clears stdin.
 * in: 
 * out: true or false
 */
int play_again();

/* ---------------- Logic ----------------*/

/*
 * computer_choice 
 * Get computers choice (including some AI,
 * if 4 coins or less left, function makes a 
 * smart choice else random).
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int computer_choice(int pile);

/*
 * toggle
 * Switches player, if HUMAN in COMPUTER out
 * etc.
 * in:  actual player
 * out: next player
 */
int toggle( int player );

/* --------------------- Utilities -------------*/
void clear_stdin();

/***************************************************
 *
 *    MAIN
 *
 ***************************************************/
int main(){
  int pile,			/* This is how many coins we have */
    player,			/* Who is playing? */
    n_coins;			/* Number of coins taken */
  bool play = true;  

    int i = 0;
  
  srand( time(0) );		/* Setup random */

  printf("Welcome to NIM by group 5!\n");
 
 
  
  pile = MAX_COINS;		/* Set start values (= init) */
  player = HUMAN;

  /* 
   *  Program main loop 
   */
  while( play ) {	
    

    printf("There are %d coins in the pile\n", pile );
    
    if( player == HUMAN ){
      n_coins = human_choice(pile);      
    }else{
      n_coins = computer_choice(pile);
      printf("- I took %d\n", n_coins);      
    }
    pile -= n_coins;
    player = toggle( player );
      
    if( pile <= 1 ){
      write_winner(player); 

      if (play_again()){
        pile = MAX_COINS;		/* Reset start values */
        player = HUMAN;
        play = true;
      } else {
        play = false;
      }
    }
  }
  /*
   * end main loop
   */
   
  //write_winner( player ); 
  

 
  puts("Thanks for playing");

  return 0;
}

/******************************************************
 *
 *  DEFINITIONS
 * 
 ******************************************************/


void clear_stdin(){
  while( getchar() != '\n' ){

  }
}

int human_choice(int pile){
  int choice, resCode;
  puts("How many coins do you want to take? ");
  scanf("%d", &choice);
  clear_stdin();
  while (choice > 3 || choice >= pile){
    puts("Too many coins chosen. Please pick another amount.");
    scanf("%d", &choice);
  }
  return choice;
}

int computer_choice(int pile){
  int choice;
  if (pile <= 4){
    choice = pile - 1;
  } else {
    choice = rand() % 3 + 1;
  }
  return choice;
}

void write_winner(int player){
  if (player == 1){
    printf("Congrats human, you have won. ");
  } else {
    printf("The computer won, better luck next time. ");
  }
}

int play_again(){
  char c;
  puts("Wanna play again?");
  scanf("%c", &c);
  clear_stdin();
  if(c == 'n' || c == 'N'){
    return false;
  } else {
    return true;
  }
}

int toggle( int player ){
  if (player == 1){
    return 0;
  } else {
    return 1;
  }
}
