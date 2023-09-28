#include <stdio.h>
#include <stdlib.h>

struct student { char name[30]; char genre; float grade; };

int main(int argc, char ** argv, char ** envp){
	struct student * students = (struct student *) malloc(4 * sizeof(struct student));
	int i = 0;
	
	for(i=0; i < 4; i++){
		fflush(stdin);
		
		printf("student name %d: ", i);
		gets((students+i)->name);
		
		printf("student genre %d: ", i);
		scanf("%c", &((students+i)->genre));
		
		printf("student grade %d: ", i);
		scanf("%f", &((students+i)->grade));
		
		printf("\n");
	}
	
	printf("%-15s| %-15s| %-15s\n", "name", "genre", "grade");
	printf("---------------------------------------\n");
	
	for(i=0; i < 4; i++){
		printf("%-15s| %-15c| %-15.2f\n", (students+i)->name, (students+i)->genre, (students+i)->grade);
	}
	
	free(students);
	students = 0;
	
	return 0;
}
