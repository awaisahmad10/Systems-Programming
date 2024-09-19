#include <stdio.h>
int main() {
	//open Input.txt for reading
	FILE* file1;
	file=fopen("Input.txt","r");
	// if the file doesn't open, output an error and return 0
	if (!file1) {
		printf("File cannot be opened\n");
		return 0;
	}
	
	//initialize variables for reading the characters in the file
	char characters[10000]; //assuming maximum 10000 characters in Input.txt
	int i=0;
	char j;
	
	// loop through each character in Input.txt
	while (fscanf(file1, "%c", &j)==1) {
		//if the character is a, change it to b
		if (j=='a') {
			j='b';
		}
		//put the current character into the character array
		characters[i]=j;
		i++;
	}
	//close Input.txt
	fclose(file1);
}
