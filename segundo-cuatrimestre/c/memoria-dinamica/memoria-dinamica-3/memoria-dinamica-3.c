#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv, char ** envp){
	int quantity;
	
	printf("numbers quantity limit: ");
	scanf("%d", &quantity);
	
	int numbers[quantity];
	int * numbers_pointer;
	
	numbers_pointer = (int *) malloc(quantity * sizeof(numbers));
	
	printf("\n");
	
	int i = 0;
	
	for(i=0; i < quantity; i++){
		printf("number %d: ", i);
		scanf("%d", numbers_pointer+i);
	}
	
	printf("\n%-15s| %-15s\n", "position", "value");
	printf("----------------------\n");
	
	for(i=0; i < quantity; i++){
		printf("%-15d| %-15d\n", i, *(numbers_pointer+i));
	}
	
	free(numbers_pointer);
	numbers_pointer = 0;
	
	return 0;
}
