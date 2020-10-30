#include<stdio.h>

int main(){
	int N = 0, M = 0;
	while(scanf("%d %d", &M, &N) != EOF){
		int sum = 0;
		if(M > 1) {
			sum += M - 1;
		} 
		if(N > 1){
			sum += (N - 1) * M;
		}
		
		printf("%d\n", sum);
	}
	return 0;
}