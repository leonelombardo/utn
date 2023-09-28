#include <stdio.h>

struct Date { int day; int month; int year; };

int main(){
	struct Date today;
	
	today.day = 29;
	today.month = 2;
	today.year = 2005;
	
	printf("today is %02d/%02d/%d", today.month, today.day, today.year);
	
	fix_date(&today);
	
	printf("\nfixed date %02d/%02d/%d", today.month, today.day, today.year);
	
	return 0;
}

void fix_date(struct Date * pointer){
	if(pointer -> day == 29 && pointer -> month == 2){
		pointer -> day = 1;
		pointer -> month = 3;
	}
}
