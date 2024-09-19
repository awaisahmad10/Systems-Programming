#include <stdio.h>
int main() {
	//open Inout.txt for reading
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

	//open Heaven.txt for writing
	FILE* file2;
	file2=fopen("Heaven.txt","w");
	//if the file doesn't open, output an error and return 0
	if (!file2) {
		printf("File 2 cannot be opened\n");
		return 0;
	}

	//loop through the new file and append each character to Heaven.txt
	for (int k=0; k<i; k++) {
		fprintf(file2, "%c", characters[k]);
	}
	
	//close Heaven.txt
	fclose(file2);
	return 0;
}
