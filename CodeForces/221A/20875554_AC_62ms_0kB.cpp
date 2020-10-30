#include<stdio.h>

int main(){
	
	int n;
	
	scanf("%d", &n);
	
	if(n > 1) printf("%d ", n);
	
	int a;
	for(a=1; a<n-1; a++){
		printf("%d ", a);
	}
	printf("%d\n", a);
	
	return 0;
}
