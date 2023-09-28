#include <stdio.h>

struct Student { char name[20]; char genre; int grade; };

int main(){
	const length = 5;
	struct Student vector[length], * pointer;
	struct Student temporal;
	int i = 0, j = 0;
	
	for(pointer=vector, i=0; pointer < vector + length; pointer++, i++){
		fflush(stdin);
		
		printf("student name %d: ", i);
		gets(pointer -> name);
		
		printf("student genre %d: ", i);
		pointer -> genre = getchar();
		
		printf("student grade %d: ", i);
		scanf("%d", &(pointer -> grade));
		
		printf("\n");
	}
	
	printf("\n\n%-15s| %-15s| %-15s\n", "name", "genre", "grade");
	printf("---------------------------------------\n");
	
	for(pointer=vector; pointer < vector + length; pointer++){
		printf("%-15s| %-15c| %-15d\n", pointer -> name,pointer -> genre, pointer -> grade);
	}
	
	printf("\n\n%-15s| %-15s| %-15s\n", "name", "genre", "grade");
	printf("---------------------------------------\n");
	
	for(i=0; i < length - 1; i++){
		pointer = vector;
		
		for(j=0; j < length - i - 1; j++){
			if((pointer + j) -> grade < (pointer + j + 1) -> grade){
				temporal = * (pointer + j);
				* (pointer + j) = * (pointer + j + 1);
				* (pointer + j + 1) = temporal;
			}
		}
	}
	
	for(pointer=vector; pointer < vector + length; pointer++){
		printf("%-15s| %-15c| %-15d\n", pointer -> name,pointer -> genre, pointer -> grade);
	}
	
	return 0;
}
