#include<stdio.h>


int main(){
	int tc = 0;
	int n = 0;
	int x = 0;
	scanf("%d", &tc);
	for(int a=0; a<tc; a++){
		int max = 0, min = 100;
		scanf("%d", &n);
		for(int a=0; a<n; a++){
			scanf("%d", &x);
			if(x > max) max = x;
			if(x < min) min = x;
		}
		printf("%d\n", (max - min) * 2);
	}
	return 0;
}