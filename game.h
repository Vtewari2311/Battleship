#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#ifndef game_h
#define game_h

void printc(char);
void prints(char*);
void println();
int numCheck(int);
int isValidShip(int, int, int, int);
int isValidGuess(int, int, char);
void printBoard(char, int, int);
int checkName(char**, char*);

#endif
