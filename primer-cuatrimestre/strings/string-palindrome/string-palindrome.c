#include <stdio.h>
#include <string.h>
#include <ctype.h>

char * remove_white_space(char []);
int is_palindrome(char [], char[]);

int main(){
	char first_string[20];
	char second_string[20];
	
	printf("first word: ");
	gets(first_string);

	printf("second word: ");
	gets(second_string);
	
	char * first = remove_white_space(first_string);
	char * second = remove_white_space(second_string);
	
	if(is_palindrome(first, second)){
		printf("\n%s and %s are palindrome", first_string, second_string);
	}else{
		printf("\n%s and %s are not palindrome", first_string, second_string);
	}
	
	return 0;
}

char* remove_white_space(char string[]){
    int i = 0, counter = 0;

    for(i=0; string[i] != '\0'; i++)
    {
        string[i] = string[i + counter];

        if(string[i] == ' ' || string[i] == '\t')
        {
            counter++;
            i--;
        }
    }
    
    return string;
}

int is_palindrome(char first[], char second[]){
	int i = 0, result = 0;
	
	for(i=0; i < strlen(first); i++){
		int compare = strcmp(first, second);
		
		if(compare == 0){
			int equal = tolower(first[i]) == tolower(second[strlen(second) - i]);
			
			if(equal){
				result = 0;
			}else{
				result = 1;
			}
		}else{
			result = 0;
		}
	}
	
	return result;
}
