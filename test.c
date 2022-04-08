#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "game.h"
#include "record.h"
#include "io.h"

int main(int argc, char ** argv) {

    char * user = malloc(20);
    char * numInput = malloc(20);
    int num, check, index;
    int count = 0;

    char ** fileContents = loadGame(argv[1]);
    char ** copyOfFileContents = loadGame(argv[1]);

    prints("Welcome to Battle Ship!");
    println();

    prints("Enter in a username: ");
    read(STDIN_FILENO, user, 20); //get input
    println();

    if (index == 1) {
      prints("matches\n");
    } else {
      prints("doesn't match need to add to array\n");

      for (int i = 0; i < sizeof(fileContents); i++) {
        if (fileContents[i] == NULL) {
          fileContents[i] = user;
          user[strlen(user) - 1] = '\0';
          break;
        }
      }
    }
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

      if (checkValidNum == 1) {
        num = atoi(numInput);
      } else {
        while (checkValidNum == 0) {
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

          if (checkValidNum == 1) {
            num = atoi(numInput);
            break;
          }
        }
      }

      char * checker = malloc(4 * sizeof(char));
      char * other = malloc(4 * sizeof(char ** ));
      int counter = 0;

      if (num == 1) {
        checker = hideShip(fileContents, user); //so far only works for new users
        checker[strlen(checker)] = '\0';
      }

      int toSave = saveGame(fileContents, argv[1]);
        }
    }
