#include <stdio.h>
#include <stdlib.h>

struct Student { char name[20]; char genre; int age; };

int main(int argc, char * argv[], char * envp[]){
	const length = 2;
	struct Student student;
	FILE * file_pointer = fopen("db", "ab");
	int is_null = file_pointer == NULL;
	
	if(is_null){
		printf("error opening file");
		exit(1);
	}
	
	int i = 0;
	
	for(i=0; i < length; i++){
		fflush(stdin);
		
		printf("name: ");
		gets(student.name);
		
		printf("genre: ");
		student.genre = getchar();
		
		printf("age: ");
		scanf("%d", &student.age);
		
		printf("\n");
		
		fwrite(&student, sizeof(student), 1, file_pointer);
	}
	
	fclose(file_pointer);
	
	return 0;
}
