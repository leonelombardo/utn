#include <stdio.h>

int main(){
	int a = 25;
	int b = 25;
	
	int * pointer = &a;
	
	printf("%-15s| %-15s| %-15s\n", "variable", "value", "direction");
	printf("-------------------------------------------\n");
	
	printf("%-15s| %-15d| %-15x \n", "a", a, &a);
	printf("%-15s| %-15d| %-15x\n", "pointer", * pointer, pointer);
	
	return 0;
}
