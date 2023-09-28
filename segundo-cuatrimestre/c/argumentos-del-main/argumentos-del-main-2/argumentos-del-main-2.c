#include <stdio.h>

int main(int argc, char ** argv){
	int i = 0;
	
	if(argc != 3){
		printf("invalid args quantity");
		exit(1);
	}
	
	printf("\n");
	
	for(i=0; i < atoi(* (argv + 1)); i++){
		printf("%d) %s\n", i+1, * (argv + 2));
	}
	
	return 0;
}
