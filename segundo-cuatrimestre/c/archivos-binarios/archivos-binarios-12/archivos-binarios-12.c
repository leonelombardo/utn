#include <stdio.h>
#include <stdlib.h>

struct Student { char name[20]; char genre; int age; };

int main(int argc, char * argv[], char * envp[]){
	struct Student student;
	FILE * file_pointer = fopen("db", "r+b");
	int is_null = file_pointer == NULL;
	
	if(is_null){
		printf("error opening file");
		exit(1);
	}
	
	printf("%-15s| %-15s| %-15s\n", "name", "genre", "age");
	printf("-------------------------------------\n");
	
	fread(&student, sizeof(student), 1, file_pointer);
	
	while(!feof(file_pointer)){
		printf("%-15s| %-15c| %-15d\n", student.name, student.genre, student.age);
		
		fread(&student, sizeof(student), 1, file_pointer);
	}
	
	int length = ftell(file_pointer) / sizeof(student);
	
	rewind(file_pointer);
	
	int i = 0, j = 0;
	struct Student student_x, student_y;
	
	for(i=0; i < length; i++){
		for(j=0; j < length-1; j++){
			fseek(file_pointer, j * sizeof(student), SEEK_SET);
			fread(&student_x, sizeof(student), 1, file_pointer);
			
			fseek(file_pointer, (j+1) * sizeof(student), SEEK_SET);
			fread(&student_y, sizeof(student), 1, file_pointer);
		
			if(student_x.age > student_y.age){
				fseek(file_pointer, j * sizeof(student), SEEK_SET);
				fwrite(&student_y, sizeof(student), 1, file_pointer);
				fwrite(&student_x, sizeof(student), 1, file_pointer);
				
				fseek(file_pointer, 0, SEEK_SET);
			}
		}
	}
	
	rewind(file_pointer);
	
	printf("\n%-15s| %-15s| %-15s\n", "name", "genre", "age");
	printf("-------------------------------------\n");
	
	fread(&student, sizeof(student), 1, file_pointer);
	
	while(!feof(file_pointer)){
		printf("%-15s| %-15c| %-15d\n", student.name, student.genre, student.age);
		
		fread(&student, sizeof(student), 1, file_pointer);
	}
	
	fclose(file_pointer);
	
	return 0;
}
