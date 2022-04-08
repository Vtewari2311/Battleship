#include <string.h>

#include <stdio.h>
#include <ctype.h>
#include "game.h"
#include "record.h"

int exectuable(int argc, char * argv[]) {
  char str[20];
  prints("Welcome to battleship");
  println();
  fprintf(STDIN_FILENO, "Enter user name: %s", str);
  read(STDIN_FILENO, str, 20);
  println();
  fprintf(STDIN_FILENO, "Welcome %s", str);
  read(STDIN_FILENO, str, 20);
  println();
  int num;
  do {
    prints("Main Menu");
    println();
    prints("Would you like to:");
    prints("\t 1. hide a ship");
    prints("\t 2. find a ship");
    prints("\t 3. quit");
    println();
    fprintf(STDIN_FILENO, "Enter 1-3: %d", atoi(str));
    read(STDIN_FILENO, str, 1);
    if (atoi(str) < 1 || atoi(str) > 3) {
      prints("Invalid number");
    }
    break;
  } while (atoi(str) >= 1 || atoi(str) <= 3);
  return 0;

  char * user = malloc(100);
  int num, check, index;
  int count = 0;

  char ** fileContents = loadGame(argv[1]);
  char ** copyfileContents = loadGame(argv[1]);

  prints("Welcome to Battle Ship!");
  println();

  prints("Enter in a Username:");

  index = checkName(copyfileContents, user);

  if (index == 1) {
    prints("matches \n");
  } else {
    prints("doesn't match \n");
    for (int i = 0; i < sizeof(fileContents); i++) {
      prints();
    }
  }

}
