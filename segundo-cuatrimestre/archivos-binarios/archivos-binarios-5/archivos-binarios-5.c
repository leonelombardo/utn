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
	
	printf("%-15s| %-15s| %-15s| %-15s\n", "position", "name", "genre", "age");
	printf("------------------------------------------------------\n");
	
	fread(&student, sizeof(student), 1, file_pointer);
	
	int i = 0;
	
	while(!feof(file_pointer)){
		printf("%-15d| %-15s| %-15c| %-15d\n", i, student.name, student.genre, student.age);
	
		fread(&student, sizeof(student), 1, file_pointer);
		
		i++;
	}
	
	int position;
	
	printf("\nuser position: ");
	scanf("%d", &position);
	
	while(position >= 0){
		fseek(file_pointer, position*sizeof(student), SEEK_SET);
		fread(&student, sizeof(student), 1, file_pointer);
		
		printf("\n%-15s| %-15s| %-15s| %-15s\n", "position", "name", "genre", "age");
		printf("------------------------------------------------------\n");
		printf("%-15d| %-15s| %-15c| %-15d\n", position, student.name, student.genre, student.age);
		
		printf("\nuser position: ");
		scanf("%d", &position);
	}
	
	fclose(file_pointer);
	
	return 0;
}
