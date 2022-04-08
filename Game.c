#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define new_max(x, y)(((x) >= (y)) ? (x) : (y))
#define new_min(x, y)(((x) <= (y)) ? (x) : (y))
#define len(arr)((int)(sizeof(arr) / sizeof(arr)[0]))

void printc(char c) {
  // your code here
  write(STDOUT_FILENO, & c, 1);
}

void prints(char * s) {
  write(STDOUT_FILENO, s, strlen(s));
}

void println() {
  printc('\n');
}

static int boardSize = 10;
char gameBoard[10][10];

int numCheck(int giveNum) {
  // Check if there already is an input
  char buffer[256];
  int print = write(STDOUT_FILENO, buffer, strlen(buffer));
  int read_val = read(STDIN_FILENO, buffer, strlen(buffer));
  while (read_val != 0) {
    // Check if it has an int
    if (!isdigit(read_val)) {
      giveNum = isdigit(read_val);
      // Check if the number is between [0-9], if not, continue the loop again
      if (giveNum < 48 || giveNum > 57) {
        prints("Please input a number from [0-9]");
        continue;
        // Continue going through the loop if the number is invalid
      } else {
        // Break out of the loop and return the valid number
        break;
      }
    } else {
      read_val++;
      prints("Please input a proper number and not a string");
    }
  }
  return giveNum;
}

int isValid(int x1, int y1, int x2, int y2) {
  // Both X's are the same, and it's from 0 to 9
  if (x1 == x2) {
    // Check which one is the max Y and which one is the min Y
    int max_Y = new_max(y1, y2);
    int min_Y = new_min(y1, y2);
    if (max_Y - min_Y != 3) {
      prints("The difference between them isn't 4 spaces");
      return 0;
    }
    // Once it's valid, place them on the map;
    // Go from minimum Y to maximum Y
    for (int i = min_Y; i < max_Y; i++) {
      gameBoard[x1][i] = 'x';
    }
    prints("Valid coordinate inputs");
    println();
    return 1;
  } else if (y1 == y2) {
    int max_X = new_max(x1, x2);
    int min_X = new_max(x1, x2);
    if (max_X - min_X != 3) {
      prints("The difference between them isn't 4 spaces");
      println();
      return 0;
    }
    // Once it's valid, place them on the map;
    // Go from minimum X to maximum X
    for (int i = min_X; i < max_X; i++) {
      gameBoard[i][y1] = 'x';
    }
    prints("Valid coordinate inputs");
    println();
    return 1;
  } else {
    prints("Invalid coordinates. Bow & stern must have the same value for either x or y.");
    println();
    return 0;
  }
}

int isValidGuess(int x, int y, char board[][boardSize]) {
  //if you hit the target
  if (board[x][y] == 'x') {
    // update the gameBoard
    board[x][y] = 'X';
    return 1;
  }
  // if you missed the target
  else if (board[x][y] == '.') {
    // update the gameBoard
    board[x][y] = 'O';
    return 1;
  }
  // if you already have input that same position again
  else {
    prints("That position has already been guessed");
    return 0;
  }
}

// Prints the board as shown in the examples above. If final is 0, unguessed // ship locations are displayed as periods. If final is non-zero, unguessed // ship locations are displayed as lowercase x's.
void printBoard(char board[][boardSize], int final, int fd) {
  char ** pathname;
  fd = open( * pathname, O_RDONLY);
  prints(" ");
  int column = sizeof(board[0]) / sizeof(board[0][0]);
  int row = sizeof( & board) / sizeof(board[0]);
  // printing the numbers in the Y-axis
  for (int i = 0; i < column; i++) {
    printc(i);
  }
  println();
  for (int i = 0; i < column; i++) {
    printc(i);

    for (int i = 0; i < column; i++) {
      printc(i);
      for (int j = 0; j < row; j++) {
        /*
         * Game isn't over yet, so you have to hide the    ship's position from the other
         * player
         */
        if (final == 0) {
          // Hide the ship's position from the opponent by printing a period
          if (board[i][j] == 'x') {
            printc('.');
          } else {
            prints( & board[i][j]);
          }
        }
        // if result is true, reveal everything since the match has ended
        else {
          prints( & board[i][j]);
        }
      }
      println();
    }
  }
  fd = close( ** pathname);
}

int checkName(char ** contents, char * user) {
  char key[] = " ";
  char * checks;
  // char buffer[256]
  for (int i = 0; i < sizeof(contents); i++) {
    if (contents[i] == NULL) break;

    checks = strtok(contents[i], key);
    // creates a token
    while (checks != NULL) {
      // prints(checks)
      // println;

      if (strncmp(user, checks, strlen(checks)) == 0) {
        return 1;
      }
      // prints(checks)
      // println

      checks = strtok(NULL, key);
    }
  }
  return 0;
}

int answerCheck(char * input) {
  // checks if user input is a number
  // creates temp str for input
  char str[256];

  for (int i = 0; str[i] != '\0'; ++i) {
    // puts the string/ char into str
    str[i] = input[i];
  }
  if (isdigit( * str)) {
    // checks if the str is a digit
    int toReturn = atoi(str);
    // converts digit to int
    if (toReturn < 1 || toReturn > 1) {
      println();
      return 0;
      // return false
    } else {
      return 1;
      // return true
    }
  }
  return 0;
}
