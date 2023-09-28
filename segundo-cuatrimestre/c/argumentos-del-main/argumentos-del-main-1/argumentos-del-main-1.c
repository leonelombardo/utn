#include <stdio.h>

int main(int argc, char ** argv){
	int i = 0, j = 0;
	
	printf("%-10s", "memory direction");
	
	for(i=0; i < argc; i++){
		printf("\n%d) ", i);
		printf("%-10p", * (argv + i));
	}
	
	printf("\n\n%-10s", "args");
	
	for(i=0; i < argc; i++){
		printf("\n%d) ", i);
		printf("%-10s", * (argv + i));
	}
	
	return 0;
}
