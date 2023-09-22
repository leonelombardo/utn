#include <stdio.h>
#include <stdlib.h>

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
	FILE * lawyers_pointer = fopen("lawyers", "rb");
	int is_null = fees_pointer == NULL || lawyers_pointer == NULL;
	
	if(is_null){
		printf("error opening file");
		exit(1);
	}
	
	printf("%-15s| %-15s| %-15s| %-15s\n", "client", "cause", "pay", "pay_month");
	printf("------------------------------------------------------------\n");
	
	fread(&lf_register, sizeof(lf_register), 1, fees_pointer);
	
	while(!feof(fees_pointer)){
		printf("%-15s| %-15s| %-15.2f| %-15d\n", lf_register.client, lf_register.cause, lf_register.pay, lf_register.pay_month);
		
		fread(&lf_register, sizeof(lf_register), 1, fees_pointer);
	}
	
	fclose(fees_pointer);
	
	printf("\n\n%-15s| %-15s\n", "cause", "lawyer");
	printf("-----------------------\n");
	
	fread(&lf_case, sizeof(lf_case), 1, lawyers_pointer);
	
	while(!feof(lawyers_pointer)){
		printf("%-15s| %-15s\n", lf_case.cause, lf_case.lawyer);
		
		fread(&lf_case, sizeof(lf_case), 1, lawyers_pointer);
	}
	
	fclose(lawyers_pointer);
	
	return 0;
}
