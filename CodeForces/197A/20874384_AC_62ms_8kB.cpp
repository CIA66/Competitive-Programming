#include<stdio.h>

int main(){
	
	int a, b, r;
	
	scanf("%d %d %d", &a, &b, &r);
	
	int d = r * 2;
		
	if(d <= a && d <= b) printf("First\n");
	else printf("Second\n");
	
	return 0;
}