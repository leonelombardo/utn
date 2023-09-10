#include <stdio.h>
#include <stdlib.h>

struct Student { char name[20]; char genre; int age; };

int main(int argc, char * argv[], char * envp[]){
	struct Student student;
	FILE * file_pointer = fopen("db", "rb");
	int is_null = file_pointer == NULL;
	
	if(is_null){
		printf("error opening file");
		exit(1);
	}
	
	fread(&student, sizeof(student), 1, file_pointer); 
	
	printf("%-15s| %-15s| %-15s\n", "name", "genre", "age");
	printf("-------------------------------------\n");
	
	while(!feof(file_pointer)){
		printf("%-15s| %-15c| %-15d\n", student.name, student.genre, student.age);
		
		fread(&student, sizeof(student), 1, file_pointer);
	}
	
	fclose(file_pointer);
	
	return 0;
}
