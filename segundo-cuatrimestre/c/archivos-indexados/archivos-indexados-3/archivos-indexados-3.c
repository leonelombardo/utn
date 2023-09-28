#include <stdio.h>
#include <stdlib.h>

struct Product {
	short int id;
	char code[50];
	char description[100];
	char manufacturer[50];
	short int stock;
};

int main(int argc, char * argv[], char * envp[]){
	struct Product product_x, product_y;
	FILE * file_pointer = fopen("db", "rb");
	FILE * aux_file_pointer = fopen("db", "rb");
	
	fseek(file_pointer, 0, SEEK_END);
	
	int file_length = ftell(file_pointer) / sizeof(product_x);
	int count = 0, max = 0, position = 0;
	
	rewind(file_pointer);
	
	fread(&product_x, sizeof(product_x), 1, file_pointer);
	
	int i = 0;
	
	while(!feof(file_pointer)){
		for(i=0; i < file_length; i++){
			fseek(aux_file_pointer, sizeof(product_y) * i, SEEK_SET);
			fread(&product_y, sizeof(product_y), 1, aux_file_pointer);
			
			if(strcmp(product_x.manufacturer, product_y.manufacturer) == 0){
				count++;
			}
			
			if(count > max){
				max = count;
				position = i;
			}
		}
		
		count = 0;
		
		fread(&product_x, sizeof(product_x), 1, file_pointer);
	}
	
	rewind(file_pointer);
	
	fseek(file_pointer, sizeof(product_x) * position, SEEK_SET);
	fread(&product_x, sizeof(product_x), 1, file_pointer);
	
	printf("%-15s| %-15s\n", "supplier", "products_quantity");
	printf("----------------------------------\n");
	printf("%-15s| %-15d\n", product_x.manufacturer, max);
	
	fclose(file_pointer);
	fclose(aux_file_pointer);
	
	return 0;
}
