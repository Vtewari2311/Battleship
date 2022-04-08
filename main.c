#include <string.h>
#include <stdio.h>
#include "game.h"
#include "record.h"

int answerCheck(char* s);

int main(int argc, char* argv[]) {
  char numInput[1];
  char user[20];
  int num;
  prints("Welcome to Battle Ship!");
  println();
  
  prints("Enter in a username: ");
  read(STDIN_FILENO, user, 20);//get input
  println();

  prints("Welcome: ");
  prints(user);
  println();
  println();

  prints("Main Menu\n");
  println();

  prints("Would you like to: ");
  println();

  prints("\t1. hide a ship\n");
  prints("\t2. find a ship\n");
  prints("\t3. quit\n");
  println();

  prints("Enter option [1-3]: ");
  read(STDIN_FILENO, numInput, sizeof(numInput));
  println();

  int checkValidNum = answerCheck(numInput);

  if (checkValidNum == 1){
    num = atoi(numInput);
  } else {
    while (checkValidNum == 0){
      prints("Invalid input, please enter a valid number [1-3]\n");
      println();

      prints("Would you like to: ");
      println();

      prints("\t1. hide a ship\n");
      prints("\t2. find a ship\n");
      prints("\t3. quit\n");
      println();

      prints("Enter option [1-3]: ");
      read(STDIN_FILENO, numInput, sizeof(numInput));
      println();

      checkValidNum = answerCheck(numInput);

      if (checkValidNum == 1){
        num = atoi(numInput);
        break;
      }
    }
  }
}

