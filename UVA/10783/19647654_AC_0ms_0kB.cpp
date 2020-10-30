#include<stdio.h>

int main(){
	int T = 0, one = 0, two = 0;
	scanf("%d", &T);
	for(int a=1; a<=T; a++){
		int sum = 0;
		scanf("%d", &one);
		scanf("%d", &two);
		for(int b=one; b<=two; b++){
			if(b % 2 != 0) sum += b;
		}
		printf("Case %d: %d\n", a, sum);
	}
	return 0;
}