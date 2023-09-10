#include <stdio.h>

int main(){
	const length = 5;
	int vector[length];
	int * pointer, * pointer_min;
	
	int i = 0;
	
	for(pointer=vector, i=0; pointer < vector + length; pointer++, i++){
		printf("vector[%d] = ", i);
		scanf("%d", pointer);
	}
	
	for(pointer=vector, i=0; pointer < vector + length; pointer++, i++){
		printf("\nvector[%d] = %d", i, * pointer);
	}
	
	printf("\n\n");
	
	for(pointer=vector, i=0; pointer < vector + length; pointer++, i++){
		printf("\nvector[%d] = %d", i, * pointer);
	}
	
	return 0;
}
