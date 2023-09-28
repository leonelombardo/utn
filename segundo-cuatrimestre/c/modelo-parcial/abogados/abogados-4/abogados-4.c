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
	struct Register lf_register_x, lf_register_y;
	struct Case lf_case_x, lf_case_y;
	FILE * fees_pointer = fopen("fees", "rb");
	FILE * aux_fees_pointer = fopen("fees", "rb");
	FILE * lawyers_pointer = fopen("lawyers", "rb");
	FILE * aux_lawyers_pointer = fopen("lawyers", "rb");
	int is_null = fees_pointer == NULL || aux_fees_pointer == NULL || lawyers_pointer == NULL || aux_lawyers_pointer == NULL;
	
	if(is_null){
		printf("error opening file");
		exit(1);
	}
	
	fseek(fees_pointer, 0, SEEK_END);
	fseek(lawyers_pointer, 0, SEEK_END);
	
	int fees_length = ftell(fees_pointer) / sizeof(lf_register_x);
	int lawyers_length = ftell(lawyers_pointer) / sizeof(lf_case_x);
	
	rewind(fees_pointer);
	rewind(lawyers_pointer);
	
	int i = 0, position_client = 0;
	float count_client = 0, max_client = 0;
	
	fread(&lf_register_x, sizeof(lf_register_x), 1, fees_pointer);
	
	while(!feof(fees_pointer)){
		for(i=0; i < fees_length; i++){
			fseek(aux_fees_pointer, sizeof(lf_register_y) * i, SEEK_SET);
			fread(&lf_register_y, sizeof(lf_register_y), 1, aux_fees_pointer);
			
			if(strcmp(lf_register_x.client, lf_register_y.client) == 0){
				count_client += lf_register_y.pay;
			}
			
			if(count_client > max_client){
				max_client = count_client;
				position_client = i;
			}
		}
		
		count_client = 0;
		
		fread(&lf_register_x, sizeof(lf_register_x), 1, fees_pointer);
	}
	
	fseek(fees_pointer, sizeof(lf_register_x) * position_client, SEEK_SET);
	fread(&lf_register_x, sizeof(lf_register_x), 1, fees_pointer);
	
	printf("the law firm earned a total of ($%.2f) thanks to (%s)\n", max_client, lf_register_x.client);
	
	rewind(fees_pointer);
	rewind(aux_fees_pointer);
	
	int position_lawyer = 0;
	float count_lawyer = 0, max_lawyer = 0;
	
	fread(&lf_case_x, sizeof(lf_case_x), 1, lawyers_pointer);
	
	while(!feof(lawyers_pointer)){
		for(i=0; i < lawyers_length; i++){
			fseek(aux_lawyers_pointer, sizeof(lf_case_y) * i, SEEK_SET);
			fread(&lf_case_y, sizeof(lf_case_y), 1, aux_lawyers_pointer);
			
			if(strcmp(lf_case_x.lawyer, lf_case_y.lawyer) == 0){
				fseek(fees_pointer, sizeof(lf_register_x) * i, SEEK_SET);
				fread(&lf_register_x, sizeof(lf_register_x), 1, fees_pointer);
				
				count_lawyer += lf_register_x.pay;
			}
			
			if(count_lawyer > max_lawyer){
				max_lawyer = count_lawyer;
				position_lawyer = i;
			}
		}
		
		count_lawyer = 0;
		
		fread(&lf_case_x, sizeof(lf_case_x), 1, lawyers_pointer);
	}
	
	fseek(lawyers_pointer, sizeof(lf_case_x) * position_lawyer, SEEK_SET);
	fread(&lf_case_x, sizeof(lf_case_x), 1, lawyers_pointer);
	
	printf("the lawyer that earn the most ($%.2f) for the law firm is (%s)\n", max_lawyer, lf_case_x.lawyer);
	
	fclose(fees_pointer);
	fclose(aux_fees_pointer);
	fclose(lawyers_pointer);
	fclose(aux_lawyers_pointer);
	
	return 0;
}
