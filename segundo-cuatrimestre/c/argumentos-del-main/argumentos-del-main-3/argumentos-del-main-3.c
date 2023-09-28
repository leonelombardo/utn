#include <stdio.h>

int main(int argc, char ** argv){
	int i = 0;
	float total = 0;
	
	if(argc <= 1){
		printf("invalid args quantity");
		exit(1);
	}
	
	printf("%-15s| %-15s| %-15s\n", "position", "value", "total");
	printf("----------------------------------------\n");
	
	for(i=1; i < argc; i++){
		total += atoi(* (argv + i));
	
		printf("%-15d| %-15s| %-15.2f\n", i, * (argv + i), total);
	}
	
	printf("\ntotal is %.2f and its average is %.2f", total, (float) total / (argc - 1));
	
	return 0;
}
