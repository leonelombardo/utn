#include <stdio.h>

void sort(int [], int);

int main(){
	int numbers[] = {8, 4, 6, 3, 5, 7, 2, 1};
	
	sort(numbers, 8);
	
	return 0;
}

void sort(int vector[], int times){
	int i = 0, j = 0;
	
	for(i=0; i < times; i++){
		for(j=0; j < times; j++){
			if(vector[j] > vector[j+1]){
				int aux = vector[j];
				vector[j] = vector[j+1];
				vector[j+1] = aux; 
			}
		}
	}
	
	printf("vector sorted => ");
	
	for(j=0; j < times; j++){
		printf("%d ", vector[j]);
	}
}
