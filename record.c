#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

char** loadGame(char* file) {
  //load the file

	struct stat info;
	stat(file, &info);

 	int i = 0;

	int load = open(file, O_RDONLY);
  //open file

	if (load < 0) {
    //if file can't be open exit
		prints("Game does not exist, please restart and try again\n");
		exit(1);
	}

	char* buffer = malloc(info.st_size);

	int isEmpty = read(load, buffer, info.st_size);

	if (isEmpty == 0) {
		prints("Game file is empty, please restart and try again\n");
		exit(1);
	}
	write(load, buffer, info.st_size);

	char key[] = "\n";
	char* check;
  check = strtok(buffer, key); //creates a token
	char** dict = malloc(100*sizeof(buffer)); //allocates an array

	while(check != NULL) {
		dict[i] = malloc(strlen(check+1)*sizeof(check));
    strncpy(dict[i], check, strlen(check));
    dict[i][strlen(check)] = '\0';
    i++;

		check = strtok(NULL, key);
	}
	close(load);
	
	prints("Game Loaded Successfully!\n");
	println();
	
	return dict;
	}

//write the contents from the double array into the file
int saveGame(char** contents, char* file) {

	int save = open(file, O_RDONLY | O_WRONLY); //open file

	if (save < 1) {
		prints("File could not be saved");
		return 0;
	}

	for (int i = 0; i < sizeof(contents); i ++){
		// if (contents[i] == NULL) break;

		write(save, contents[i], strlen(contents[i]));
	
		if (contents[i+1] == NULL){
			break;
		} else{
			write(save, "\n", 1);
		}
	}
	
	close(save);
	return 1; //return true
}
