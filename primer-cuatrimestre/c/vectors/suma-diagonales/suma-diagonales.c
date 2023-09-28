#include <stdio.h>
#include <stdlib.h>

const int rows = 10;
const int columns = 10;

void fill_array(int [][columns], int, int);
void print_array(int [][columns], int, int);
int sum_left(int [][columns], int, int);
int sum_right(int [][columns], int, int);

int main(){
	int array[rows][columns];
	
	fill_array(array, rows, columns);
	print_array(array, rows, columns);
	sum_left(array, rows, columns);
	sum_right(array, rows, columns);
	
	return 0;
}

void fill_array(int array[][columns], int rows, int columns){
	int i = 0, j = 0;
	
	for(i=0; i < rows; i++){
		for(j=0; j < columns; j++){
			array[i][j] = rand() % 1000;
		}
	}
}

void print_array(int array[][columns], int rows, int columns){
	int i = 0, j = 0;
	
	printf("array:");
	
	for(i=0; i < rows; i++){
		printf("\n\n");
		for(j=0; j < columns; j++){
			printf("%4d", array[i][j]);
		}
	}
	
	printf("\n\n");
}

int sum_left(int array[][columns], int rows, int columns){
	int i = 0, total = 0;
	
	for(i=0; i < rows; i++){
		total += array[i][i];
		
		printf("array[%d][%d] = %d", i, i, array[i][i]);
		getchar();
	}
	
	printf("total = %d \n\n", total);
	
	return total;
}

int sum_right(int array[][columns], int rows, int columns){
	int i = 0, total = 0;
	
	for(i=0; i < rows; i++){
		total += array[i][columns - i - 1];
		
		printf("array[%d][%d] = %d", i, columns - i - 1, array[i][columns - i - 1]);
		getchar();
	}
	
	printf("total = %d", total);
	
	return total;
}
