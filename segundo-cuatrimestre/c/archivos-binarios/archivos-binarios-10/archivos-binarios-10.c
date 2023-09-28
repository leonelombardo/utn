#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student { char name[20]; char genre; int age; };

int main(int argc, char * argv[], char * envp[]){
	struct Student student;
	FILE * file_pointer = fopen("db", "r+b");
	int is_null = file_pointer == NULL;
	
	if(is_null){
		printf("error opening file");
		exit(1);
	}
	
	int found = 0;
	
	fread(&student, sizeof(student), 1, file_pointer);
	
	while(!feof(file_pointer) && !found){
		if(strcmp(student.name, "kim") == 0){
			student.age *= 2;
		
			fseek(file_pointer, (long) (-1) * sizeof(student), SEEK_CUR);
			fwrite(&student, sizeof(student), 1, file_pointer);
			fseek(file_pointer, 0, SEEK_CUR);
			
			found = 1;
		}
		
		fread(&student, sizeof(student), 1, file_pointer);
	}
	
	fclose(file_pointer);
	
	file_pointer = fopen("db", "rb");
	
	fread(&student, sizeof(student), 1, file_pointer);
	
	printf("%-15s| %-15s| %-15s\n", "name", "genre", "age");
	printf("-------------------------------------\n");
	
	while(!feof(file_pointer)){
		printf("%-15s| %-15c| %-15d\n", student.name, student.genre, student.age);
		
		fread(&student, sizeof(student), 1, file_pointer);
	}
	
	return 0;
}
