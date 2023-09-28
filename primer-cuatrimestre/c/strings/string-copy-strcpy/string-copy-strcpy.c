#include <stdio.h>
#include <string.h>

int main(){
	char string[20];
	char longest[20];
	int i = 0;
	
	for(i=0; i < 10; i++){
		printf("word: ");
		gets(string);
		
		if(strlen(string) > strlen(longest)){
			strcpy(longest, string);
		}
	}
	
	printf("\nlongest word is %s and it contains %d letters", longest, strlen(longest));
	
	return 0;
}
