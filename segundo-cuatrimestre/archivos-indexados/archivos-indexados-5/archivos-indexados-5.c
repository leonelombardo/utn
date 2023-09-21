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
	struct Product product;
	FILE * file_pointer = fopen("db", "rb");
	int is_null = file_pointer == NULL;
	
	if(is_null){
		printf("error opening file");
		exit(1);
	}
	
	int id;
	
	printf("product id: ");
	scanf("%d", &id);
	
	fflush(stdin);
	
	fread(&product, sizeof(product), 1, file_pointer);

	while(!feof(file_pointer)){
		if(product.id == id){
			printf("\n%-15s| %-15s| %-30s| %-15s| %-15s\n", "id", "code", "description", "manufacturer", "stock");
			printf("----------------------------------------------------------------------------------------\n");
			printf("%-15d| %-15s| %-30s| %-15s| %-15d\n", product.id, product.code, product.description, product.manufacturer, product.stock);
		}
		
		fread(&product, sizeof(product), 1, file_pointer);
	}
	
	fclose(file_pointer);
	
	return 0;
}
