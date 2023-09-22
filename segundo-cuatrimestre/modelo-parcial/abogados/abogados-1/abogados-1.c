#include <stdio.h>
#include <stdlib.h>

struct Register {
	char client[20];
	char cause[20];
	float pay;
	int pay_month;
};

int main(int argc, char * argv[], char * envp[]){
	struct Register lf_register;
	FILE * fees_pointer = fopen("fees", "wb");
	int is_null = fees_pointer == NULL;
	
	if(is_null){
		printf("error opening file");
		exit(1);
	}
	
	int i = 0;
	
	for(i=0; i < 15; i++){
		printf("client: ");
		gets(lf_register.client);
		
		printf("cause: ");
		gets(lf_register.cause);
		
		printf("pay: ");
		scanf("%f", &lf_register.pay);
		
		fflush(stdin);
		
		printf("pay month: ");
		scanf("%d", &lf_register.pay_month);
		
		fflush(stdin);
		
		printf("\n");
		
		fwrite(&lf_register, sizeof(lf_register), 1, fees_pointer);
	}
	
	fclose(fees_pointer);
	
	return 0;
}
