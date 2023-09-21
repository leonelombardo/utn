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
	struct Indexed indexed;
	FILE * file_pointer = fopen("db", "rb");
	FILE * new_file_pointer = fopen("indexed-db", "w+b");
	int is_null = file_pointer == NULL || new_file_pointer == NULL;
	
	if(is_null){
		printf("error opening file");
		exit(1);
	}
	
	int i = 0;
	
	fread(&product, sizeof(product), 1, file_pointer);
	
	while(!feof(file_pointer)){
		indexed.index = i;
		indexed.product_id = product.id;
		
		fwrite(&indexed, sizeof(indexed), 1, new_file_pointer);
		fread(&product, sizeof(product), 1, file_pointer);
		
		i++;
	}
	
	fclose(file_pointer);
	rewind(new_file_pointer);
	
	printf("%-15s| %-15s\n", "index", "product_id");
	printf("---------------------------\n");
	
	fread(&indexed, sizeof(indexed), 1, new_file_pointer);
	
	while(!feof(new_file_pointer)){
		printf("%-15d| %-15d\n", indexed.index, indexed.product_id);
		
		fread(&indexed, sizeof(indexed), 1, new_file_pointer);
	}
}
