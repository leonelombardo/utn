#include <stdio.h>

int main(int argc, char ** argv, char ** envp){
	char ** envp_pointer;
	
	for(envp_pointer=envp; envp_pointer; envp_pointer++){
		printf("%s\n", * envp_pointer);
	}
	
	return 0;
}
