#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[], char * envp[]){
	char phrase[100] = "this .txt file has been written directly from c code";
	FILE * file_pointer = fopen("file.txt", "w");
	int is_null = file_pointer == NULL;
	
	if(is_null){
		printf("error opening file");
		exit(1);
	}
	
	fprintf(file_pointer, "%s", phrase);
	
	fclose(file_pointer);
	
	return 0;
}
