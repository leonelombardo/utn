#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char string[20];
	char longest[20];
	char word;
	
	int i = 0, j = 0;
	
	for(i=0; i < 10; i++){
		printf("word: ");
		gets(string);
		
		if(strlen(string) > strlen(longest)){
			strcpy(longest, string);
		}
	}
	
	for(j=0; j < strlen(longest); j++){
		if(!word){
			word = longest[j];
		}
		
		int is_lower = tolower(word) > tolower(longest[j]);
		
		if(is_lower){
			word = longest[j];
		}
	}
	
	printf("word %s contains %d letters and the lower one is %c", longest, strlen(longest), word);
	
	return 0;
}
