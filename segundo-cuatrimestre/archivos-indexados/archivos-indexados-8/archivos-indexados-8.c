#include <stdio.h>
#include <stdlib.h>

struct Product {
	short int id;
	char code[50];
	char description[100];
	char manufacturer[50];
	short int stock;
};

struct Indexed {
	int index;
	short int product_id;
};

int main(int argc, char * argv[], char * envp[]){
	struct Product product;
	struct Indexed indexed_x, indexed_y;
	int min = 0, max = 0;
	FILE * file_pointer = fopen("db", "rb");
	FILE * indexed_file_pointer = fopen("indexed-db", "r+b");
	int is_null = file_pointer == NULL || indexed_file_pointer == NULL;
	
	if(is_null){
		printf("error opening file");
		exit(1);
	}
	
	fseek(indexed_file_pointer, 0, SEEK_END);
	max = ftell(indexed_file_pointer) / sizeof(indexed_x);
	
	rewind(indexed_file_pointer);
	
	int i = 0, j = 0;
	
	for(i=0; i < max-1; i++){
		for(j=0; j < max-i-1; j++){
			fseek(indexed_file_pointer, sizeof(indexed_x) * j, SEEK_SET);
			fread(&indexed_x, sizeof(indexed_x), 1, indexed_file_pointer);
			fread(&indexed_y, sizeof(indexed_y), 1, indexed_file_pointer);
			
			if(indexed_x.product_id > indexed_y.product_id){
				fseek(indexed_file_pointer, sizeof(indexed_x) * j, SEEK_SET);
				fwrite(&indexed_y, sizeof(indexed_y), 1, indexed_file_pointer);
				fwrite(&indexed_x, sizeof(indexed_x), 1, indexed_file_pointer);
			}
		}
	}
	
	rewind(indexed_file_pointer);
	
	int found = 0;
	int med;
	int product_id = 5913;
	
	while(max > min && !found){
		med = (max + min) / 2;
		
		fseek(indexed_file_pointer, sizeof(indexed_x) * med, SEEK_SET);
		fread(&indexed_x, sizeof(indexed_x), 1, indexed_file_pointer);
		
		if(indexed_x.product_id == product_id){
			found = 1;
		}else{
			if(indexed_x.product_id > product_id){
				max = med - 1;
			}else{
				min = med + 1;
			}
		}
	}
	
	if(!found){
		printf("product not found");
	}else{
		fseek(file_pointer, sizeof(product) * indexed_x.index, SEEK_SET);
		fread(&product, sizeof(product), 1, file_pointer);
		
		printf("\n%-15s| %-15s| %-30s| %-15s| %-15s\n", "id", "code", "description", "manufacturer", "stock");
		printf("----------------------------------------------------------------------------------------\n");
		printf("%-15d| %-15s| %-30s| %-15s| %-15d\n", product.id, product.code, product.description, product.manufacturer, product.stock);
	}
	
	fclose(indexed_file_pointer);
	fclose(file_pointer);

	return 0;
}
