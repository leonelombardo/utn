#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	struct Subject subject_x, subject_y;
	FILE * teachers_pointer = fopen("teachers", "rb");
	FILE * subjects_pointer = fopen("subjects", "rb");
	FILE * aux_subjects_pointer = fopen("subjects", "rb");
	
	fseek(teachers_pointer, 0, SEEK_END);
	
	int teachers_length = ftell(teachers_pointer) / sizeof(teacher);
	
	rewind(teachers_pointer);
	
	printf("%-15s| %-15s| %-15s\n", "teacher_id", "teacher_name", "subject_name");
	printf("----------------------------------------------\n");
	
	fread(&teacher, sizeof(teacher), 1, teachers_pointer);
	fread(&subject_x, sizeof(subject_x), 1, subjects_pointer);
	
	int i = 0, j = 0;
	
	while(!feof(subjects_pointer)){
		if(subject_x.level == 3){
			for(i=0; i < teachers_length; i++){
				if(teacher.id == subject_x.teacher_id){
					printf("%-15d| %-15s| %-15s\n", teacher.id, teacher.name, subject_x.name);
				}
				
				fread(&teacher, sizeof(teacher), 1, teachers_pointer);
			}
			
			fseek(teachers_pointer, 0, SEEK_SET);
		}
		
		fread(&subject_x, sizeof(subject_x), 1, subjects_pointer);
	}
	
	fseek(teachers_pointer, 0, SEEK_END);
	
	int subjects_length = ftell(subjects_pointer) / sizeof(subject_x);
	
	rewind(teachers_pointer);
	rewind(subjects_pointer);
	
	fread(&subject_x, sizeof(subject_x), 1, subjects_pointer);
	
	int count = 0, max = 0, teacher_id = 0;
	char teacher_name[20];
	
	while(!feof(subjects_pointer)){
		for(i=0; i < subjects_length; i++){
			fseek(aux_subjects_pointer, sizeof(subject_x) * i, SEEK_SET);
			fread(&subject_y, sizeof(subject_y), 1, aux_subjects_pointer);
			
			if(subject_x.teacher_id == subject_y.teacher_id){
				count++;
			}
			
			if(count > max){
				max = count;
				teacher_id = subject_x.teacher_id;
				
				for(j=0; j < teachers_length; j++){
					fseek(teachers_pointer, sizeof(teacher) * j, SEEK_SET);
					fread(&teacher, sizeof(teacher), 1, teachers_pointer);
					
					if(teacher.id == teacher_id){
						strcpy(teacher_name, teacher.name);
					}
				}
			}
		}
		
		count = 0;
		
		fread(&subject_x, sizeof(subject_x), 1, subjects_pointer);
	}
	
	fclose(teachers_pointer);
	fclose(subjects_pointer);
	fclose(aux_subjects_pointer);
	
	printf("\n\n%-15s| %-15s| %-15s\n", "teacher_id", "teacher_name", "subjects_quantity");
	printf("---------------------------------------------------\n");
	printf("%-15d| %-15s| %-15d\n", teacher_id, teacher_name, max);
	
	return 0;
}
