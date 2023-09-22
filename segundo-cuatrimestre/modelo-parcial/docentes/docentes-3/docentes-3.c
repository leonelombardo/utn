#include <stdio.h>
#include <stdlib.h>

struct Teacher {
	int id;
	char name[20];
};

struct Subject {
	char name[20];
	int level;
	int teacher_id;
};

int main(int argc, char * argv[], char * envp[]){
	struct Teacher teacher;
	struct Subject subject;
	FILE * teachers_pointer = fopen("teachers", "rb");
	FILE * subjects_pointer = fopen("subjects", "rb");

	printf("%-15s| %-15s\n", "id", "name");
	printf("----------------------\n");

	fread(&teacher, sizeof(teacher), 1, teachers_pointer);

	while(!feof(teachers_pointer)){
		printf("%-15d| %-15s\n", teacher.id, teacher.name);
		fread(&teacher, sizeof(teacher), 1, teachers_pointer);	
	}
	
	fclose(teachers_pointer);
	
	printf("\n\n%-15s| %-15s| %-15s\n", "teacher_id", "level", "subject_name");
	printf("----------------------------------------------\n");

	fread(&subject, sizeof(subject), 1, subjects_pointer);

	while(!feof(subjects_pointer)){
		printf("%-15d| %-15d| %-15s\n", subject.teacher_id, subject.level, subject.name);
		fread(&subject, sizeof(subject), 1, subjects_pointer);
	}
	
	fclose(subjects_pointer);
	
	return 0;
}
