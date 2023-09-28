#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[], char * envp[]){
	char character;
	FILE * original_file_pointer = fopen("file.txt", "r");
	FILE * duplicate_file_pointer = fopen("file-copy.txt", "w");
	int is_null = original_file_pointer == NULL || duplicate_file_pointer == NULL;
	
	if(is_null){
		printf("error opening file");
		exit(1);
	}
	
	character = getc(original_file_pointer);
	
	while(!feof(original_file_pointer)){
		putc(character, duplicate_file_pointer);
		character = getc(original_file_pointer);
	}
	
	fclose(original_file_pointer);
	fclose(duplicate_file_pointer);
	
	return 0;
}
