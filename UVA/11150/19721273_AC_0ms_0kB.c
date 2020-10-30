#include<stdio.h>

int main(){
	int N;
	while(scanf("%d", &N) != EOF){
		printf("%d\n", N + (N / 2));
	}
	return 0;
}