#include <stdio.h>
#include <time.h>

int main(){
	time_t t;
	struct tm current_time, * pointer;
	
	t = time(0);
	pointer = localtime(&t);
	
	current_time = * pointer;
	
	printf("%02d/%02d/%02d %02d:%02d:%02d", current_time.tm_mday, 1 + current_time.tm_mon, 1900 + current_time.tm_year, current_time.tm_hour, current_time.tm_min, current_time.tm_sec);

	return 0;
}
