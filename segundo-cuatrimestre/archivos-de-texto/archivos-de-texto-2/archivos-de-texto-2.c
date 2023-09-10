#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[], char * envp[]){
	char character;
	FILE * file_pointer = fopen("file.txt", "r");
	int is_null = file_pointer == NULL;
	
	if(is_null){
		printf("error opening file");
		exit(1);
	}
	
	character = getc(file_pointer);
	
	while(character != EOF){
		putchar(character);
		character = getc(file_pointer);
	}
	
	fclose(file_pointer);
	
	return 0;
}
