#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "generator.c"

// declare clock to track time elapsed
clock_t clock(void);
int main() {
	FILE* f;
	// initiate variables for tracking time
	clock_t start, end,total_time;
	// Create Spam.txt to write characters into
	f = fopen("Spam.txt","w");
	if (f == NULL) {
		return -1;
	}
	//start the clock
	start = clock();
	//call generate function on Spam.txt
	generate(f);
	//end the clock
	end = clock();
	//calculate the time passed
	total_time = (end - start);
	//output this to the terminal
	printf("Total time= %f sec\n",(float) total_time/CLOCKS_PER_SEC);
	//Sclose the file
	fclose(f);
	return 0;
}
