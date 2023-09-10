#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[], char * envp[]){
	char character;
	FILE * encrypted_file_pointer = fopen("encrypted-file.txt", "r");
	FILE * decrypted_file_pointer = fopen("decrypted-file.txt", "w");
	int is_null = encrypted_file_pointer == NULL || decrypted_file_pointer == NULL;
	
	if(is_null){
		printf("error opening file");
		exit(1);
	}

	character = getc(encrypted_file_pointer);
	
	while(!feof(encrypted_file_pointer)){
		putc(character - 5, decrypted_file_pointer);
		character = getc(encrypted_file_pointer);
	}
	
	fclose(encrypted_file_pointer);
	fclose(decrypted_file_pointer);
	
	return 0;
}
