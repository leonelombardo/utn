#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[], char * envp[]){
	rename("db", "db-new-name");
	remove("db-to-remove");
	
	return 0;
}
