#include <stdio.h>

int main(){
	const length = 5;
	int vector[length];
	int * pointer;
	
	int i = 0;
	
	for(i=0; i < length; i++){
		printf("vector[%d] = ", i);
		scanf("%d", &vector[i]);
	}
	
	for(i=0; i < length; i++){
		printf("\nvector[%d] = %d", i, vector[i]);
	}
	
	printf("\n\n");
	
	for(pointer=vector, i=0; pointer < vector + length; pointer++, i++){
		printf("vector[%d] = ", i);
		scanf("%d", pointer);
	}
	
	for(pointer=vector, i=0; pointer < vector + length; pointer++, i++){
		printf("\nvector[%d] = %d", i, * pointer);
	}
	
	printf("\n");
	
	for(pointer=vector, i=0; i < length; i++){
		printf("\nvector[%d] = %d", i, * (pointer + i));
	}
	
	return 0;
}
