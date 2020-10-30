#include<stdio.h>

int main(){
	// 1 000 000 001
	// +- 2 147 483 647 -> kapasitas int
	
	int t = 0;
	scanf("%d", &t);
	for(int a=0; a<t; a++){
		int first = 0, second = 0;
		scanf("%d %d", &first, &second);
		if(first < second) printf("<\n");
		else if(first > second) printf(">\n");
		else printf("=\n");
	}
	
	return 0;
}