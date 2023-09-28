#include <stdio.h>
#include <stdlib.h>

struct Indexed {
	int index;
	short int product_id;
};

int main(int argc, char * argv[], char * envp[]){
	struct Indexed indexed, indexed_copy;
	FILE * file_pointer = fopen("indexed-db", "r+b");
	FILE * tmp_file_pointer = tmpfile();
	int is_null = file_pointer == NULL;
	
	if(is_null){
		printf("error opening file");
		exit(1);
	}
	
	fread(&indexed, sizeof(indexed), 1, file_pointer);
	
	while(!feof(file_pointer)){
		indexed_copy.index = indexed.index;
		indexed_copy.product_id = indexed.product_id;
		
		fwrite(&indexed_copy, sizeof(indexed_copy), 1, tmp_file_pointer);
		
		fread(&indexed, sizeof(indexed), 1, file_pointer);
	}

	fclose(file_pointer);

	int length = ftell(tmp_file_pointer) / sizeof(indexed);
	
	rewind(tmp_file_pointer);
	
	printf("%-15s| %-15s\n", "index", "product_id");
	printf("---------------------------\n");
	
	int i = 0, j = 0;
	struct Indexed indexed_x, indexed_y;
	
	for(i=0; i < length; i++){
		for(j=0; j < length-1; j++){
			fseek(tmp_file_pointer, j * sizeof(indexed), SEEK_SET);
			fread(&indexed_x, sizeof(indexed), 1, tmp_file_pointer);
			
			fseek(tmp_file_pointer, (j+1) * sizeof(indexed), SEEK_SET);
			fread(&indexed_y, sizeof(indexed), 1, tmp_file_pointer);
			
			if(indexed_x.product_id > indexed_y.product_id){
				fseek(tmp_file_pointer, j * sizeof(indexed), SEEK_SET);
				fwrite(&indexed_y, sizeof(indexed), 1, tmp_file_pointer);
				fwrite(&indexed_x, sizeof(indexed), 1, tmp_file_pointer);
			
				fseek(tmp_file_pointer, 0, SEEK_SET);
			}
		}
	}
	
	rewind(tmp_file_pointer);
	
	fread(&indexed, sizeof(indexed), 1, tmp_file_pointer);
	
	while(!feof(tmp_file_pointer)){
		printf("%-15d| %-15d\n", indexed.index, indexed.product_id);
		
		fread(&indexed, sizeof(indexed), 1, tmp_file_pointer);
	}
	
	fclose(tmp_file_pointer);
	
	return 0;
}
