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
	
	for(pointer_min=pointer=vector; pointer < vector + length; pointer++){
		if(* pointer < * pointer_min){
			pointer_min = pointer;
		}
	}
	
	printf("\n\nlower value is %d and its position is %d", * pointer_min, pointer_min-vector);
	
	return 0;
}
