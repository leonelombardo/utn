#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Register {
	char client[20];
	char cause[20];
	float pay;
	int pay_month;
};

struct Case {
	char cause[20];
	char lawyer[20];
};


int main(int argc, char * argv[], char * envp[]){
	struct Register lf_register;
	struct Case lf_case;
	FILE * fees_pointer = fopen("fees", "rb");
	FILE * lawyers_pointer = fopen("lawyers", "wb");
	int is_null = lawyers_pointer == NULL || fees_pointer == NULL;
	
	if(is_null){
		printf("error opening file");
		exit(1);
	}
	
	fseek(fees_pointer, 0, SEEK_END);
	
	int fees_length = ftell(fees_pointer) / sizeof(lf_register);
	
	rewind(fees_pointer);

	fread(&lf_register, sizeof(lf_register), 1, fees_pointer);

	int i = 0;

	for(i=0; i < fees_length; i++){
		printf("lawyer for case (%s) from (%s): ", lf_register.cause, lf_register.client);
		
		gets(lf_case.lawyer);
		
		strcpy(lf_case.cause, lf_register.cause);
		
		fwrite(&lf_case, sizeof(lf_case), 1, lawyers_pointer);
		
		fread(&lf_register, sizeof(lf_register), 1, fees_pointer);
	}
	
	fclose(fees_pointer);
	fclose(lawyers_pointer);
	
	return 0;
}
