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
	
	int men = 0, women = 0;
	float men_total = 0, women_total = 0;
	
	while(!feof(file_pointer)){
		printf("%-15s| %-15c| %-15d\n", student.name, student.genre, student.age);
		
		men += student.genre == 'm' && 1;
		women += student.genre == 'f' && 1;
		
		men_total += student.genre == 'm' ? student.age : 0;
		women_total += student.genre == 'f' ? student.age : 0;
		
		fread(&student, sizeof(student), 1, file_pointer);
	}
	
	printf("\nmen quantity (%d) age average (%.2f)\n", men, men_total / men);
	printf("women quantity (%d) age average (%.2f)", women, women_total / women);
	
	fclose(file_pointer);
	
	return 0;
}
