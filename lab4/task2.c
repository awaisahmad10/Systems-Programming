#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	//open Spam.txt for reading
	FILE* f;
	f=fopen(argv[1],"r");
	if (f==NULL) {
		return -1;
	}
	// check if there's enough arguments
	if (argc < 2) {
		printf("Need more arguments\n");
	}
	//initialize variables
	int num_of_occur = 0;
	int c;
	// loop through the file and check if the character matches
	while (( c = getc(f)) != EOF ) {
		if (c == *argv[2]) {
			num_of_occur++;
		}
	}
	//close the file
	fclose(f);
	printf("There are %d instances of %s in %s\n", num_of_occur, argv[2], argv[1]);
	return 0;
}
