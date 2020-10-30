#include<stdio.h>

int main(){
	int current = 0, gotoo = 0;
	int thiss = 0, that = 0;
	while(1){
		scanf("%d %d", &current, &gotoo);
		if(current == -1 && gotoo == -1) break;
		thiss = gotoo - current;
		if(thiss < 0) thiss *= -1;
		that = 100 - thiss;
		
		if(thiss < that) printf("%d\n", thiss);
		else printf("%d\n", that);
		
	}
	return 0;
}