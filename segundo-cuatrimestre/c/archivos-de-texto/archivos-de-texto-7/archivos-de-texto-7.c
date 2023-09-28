#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[], char * envp[]){
	char character;
	FILE * file_pointer = fopen("archivos-de-texto-1.c", "rb");
	int is_null = file_pointer == NULL;
	
	if(is_null){
		printf("error opening file");
		exit(1);
	}
	
	character = getc(file_pointer);
	
	int i = 0;
	
	while(!feof(file_pointer)){
		printf("%02x ", character);
		character = getc(file_pointer);
		
		i++;
	}
	
	printf("\n\nthe size of this file is %d bytes", i);
	
	fclose(file_pointer);
	
	return 0;
}
