#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[], char * envp[]){
	char character;
	FILE * file_pointer = fopen("file.txt", "w");
	int is_null = file_pointer == NULL;
	
	if(is_null){
		printf("error opening file");
		exit(1);
	}
	
	character = getchar();
		
	while(character != '$'){
		putc(character, file_pointer);
		character = getchar();
	}
	
	fclose(file_pointer);
	
	return 0;
}
