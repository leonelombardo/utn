#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv, char ** envp){
	int a = 25;
	int * b;
	
	b = (int *) malloc(4);
	
	* b = a;
	
	printf("b direction in the heap is %p\n", b); 
	printf("* b value is %d", * b);
	
	free(b);
	b = 0;
	
	return 0;
}
