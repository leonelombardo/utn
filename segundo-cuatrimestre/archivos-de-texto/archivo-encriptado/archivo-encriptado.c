#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[], char * envp[]){
	char character;
	FILE * original_file_pointer = fopen("file.txt", "r");
	FILE * encrypted_file_pointer = fopen("encrypted-file.txt", "w");
	int is_null = original_file_pointer == NULL || encrypted_file_pointer == NULL;
	
	if(is_null){
		printf("error opening file");
		exit(1);
	}
	
	character = getc(original_file_pointer);
	
	while(!feof(original_file_pointer)){
		putc(character + 5, encrypted_file_pointer);
		character = getc(original_file_pointer);
	}
	
	fclose(original_file_pointer);
	fclose(encrypted_file_pointer);
	
	return 0;
}
