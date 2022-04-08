#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef record_h
#define record_h

char** loadGame(char*);
int saveGame(char**, char*);

#endif
