#include <stdio.h>
#include <stdlib.h>

struct Subject {
	char name[20];
	int level;
	int teacher_id;
};

int main(int argc, char * argv[], char * envp[]){
	struct Subject subject;
	FILE * subjects_pointer = fopen("subjects", "wb");
	int is_null = subjects_pointer == NULL;
	
	if(is_null){
		printf("error opening file");
		exit(1);
	}
	
	int i = 0;
	
	for(i=0; i < 15; i++){
		printf("subject name: ");
		gets(subject.name);
		
		printf("subject level: ");
		scanf("%d", &subject.level);
		
		fflush(stdin);
		
		printf("teacher id: ");
		scanf("%d", &subject.teacher_id);
		
		fflush(stdin);
	
		fwrite(&subject, sizeof(subject), 1, subjects_pointer);
		
		printf("\n");
	}
	
	fclose(subjects_pointer);
	
	return 0;
}
