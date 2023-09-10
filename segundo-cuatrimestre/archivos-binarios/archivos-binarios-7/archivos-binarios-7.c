#include <stdio.h>
#include <stdlib.h>

struct Student { char name[20]; char genre; int age; };

int main(int argc, char * argv[], char * envp[]){
	struct Student student;
	FILE * file_pointer = fopen("db", "rb");
	FILE * file_correction_pointer = fopen("modified-db", "wb");
	int is_null = file_pointer == NULL || file_correction_pointer == NULL;
	
	if(is_null){
		printf("error opening file");
		exit(1);	
	}
	
	printf("%-15s| %-15s| %-15s\n", "name", "genre", "age");
	printf("-------------------------------------\n");
	
	fread(&student, sizeof(student), 1, file_pointer);
	
	while(!feof(file_pointer)){
		printf("%-15s| %-15c| %-15d\n", student.name, student.genre, student.age);
		
		if(student.genre == 'f'){
			student.age *= 2;
		}
		
		fwrite(&student, sizeof(student), 1, file_correction_pointer);
	
		fread(&student, sizeof(student), 1, file_pointer);
	}
	
	fclose(file_correction_pointer);
	file_correction_pointer = fopen("modified-db", "rb");
	
	printf("\n%-15s| %-15s| %-15s\n", "name", "genre", "age");
	printf("-------------------------------------\n");
	
	fread(&student, sizeof(student), 1, file_correction_pointer);
	
	while(!feof(file_correction_pointer)){
		printf("%-15s| %-15c| %-15d\n", student.name, student.genre, student.age);
		
		fread(&student, sizeof(student), 1, file_correction_pointer);
	}
	
	fclose(file_pointer);
	fclose(file_correction_pointer);
	
	return 0;
}
