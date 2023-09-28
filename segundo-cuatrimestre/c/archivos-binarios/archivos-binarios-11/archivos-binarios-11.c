#include <stdio.h>
#include <stdlib.h>

struct Student { char name[20]; char genre; int age; };

int main(int argc, char * argv[], char * envp[]){
	struct Student student;
	FILE * file_pointer = fopen("db", "rb");
	FILE * temp_file_pointer = tmpfile();
	int is_null = file_pointer == NULL || temp_file_pointer == NULL;
	
	if(is_null){
		printf("error opening file");
		exit(1);
	}
	
	fread(&student, sizeof(student), 1, file_pointer);
	
	while(!feof(file_pointer)){
		if(student.genre == 'm'){
			fwrite(&student, sizeof(student), 1, temp_file_pointer);
		}
		
		fread(&student, sizeof(student), 1, file_pointer);
	}
	
	fclose(file_pointer);
	rewind(temp_file_pointer);
	
	file_pointer = fopen("db", "wb");
	
	printf("%-15s| %-15s| %-15s\n", "name", "genre", "age");
	printf("-------------------------------------\n");
	
	fread(&student, sizeof(student), 1, temp_file_pointer);
	
	while(!feof(temp_file_pointer)){
		printf("%-15s| %-15c| %-15d\n", student.name, student.genre, student.age);
		
		fwrite(&student, sizeof(student), 1, file_pointer);
		fread(&student, sizeof(student), 1, temp_file_pointer);
	}
	
	fclose(file_pointer);
	remove(temp_file_pointer);
	
	return 0;
}
