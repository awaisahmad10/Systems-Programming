#include<stdio.h>
#include<conio.h>

void main() {
	
	int num_of_int;
	int array[1000];
	int temp_num;
	printf("Enter the number of elements\n");
	scanf("%d", num_of_int);
	printf("Enter %d integers\n", num_of_int);
	
	for (int i=0; i<n; i++) {
		scanf("%d", array[i]);
	}
	printf("Sorted list in ascending order: \n");
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n-i; j++) {
			if (array[j] > array[j+1]) {
				temp_num = array[j];
				array[j] = array[j+1];
				array[j+1] = temp_num;
			}
		}
	}
	
	for (int i=0; i<n; i++) {
		printf("%d", array[i]);
	}
}
