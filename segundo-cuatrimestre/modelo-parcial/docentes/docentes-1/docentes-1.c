#include <stdio.h>
#include <stdlib.h>

struct Teacher {
	int id;
	char name[20];
};

int main(int argc, char * argv[], char * envp[]){
	struct Teacher teacher;
	FILE * teachers_pointer = fopen("teachers", "wb");
	int is_null = teachers_pointer == NULL;
	
	if(is_null){
		printf("error opening file");
		exit(1);
	}

	int i = 0;
	
	for(i=0; i < 3; i++){
		printf("teacher name: ");
		gets(teacher.name);
		
		teacher.id = i;
		
		fwrite(&teacher, sizeof(teacher), 1, teachers_pointer);
	}
	
	fclose(teachers_pointer);
	
	return 0;
}
