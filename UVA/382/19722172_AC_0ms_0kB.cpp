#include<stdio.h>

int main(){
	int N = 0;
	int start = 0;
	while(1){
		scanf("%d", &N);
		if(start == 0){
			printf("PERFECTION OUTPUT\n");
			start = 1;
		}
		if(N == 0) break;
		int sum = 0;
		int temp = 0;
		for(int b=1; b<N; b++){
			temp = N / b;
			if((temp != -1) && (temp != 1) && (N % b == 0)){
				sum += b;
			}
			if(sum > N){
				printf("%5d  ABUNDANT\n", N);
				break;
			}
		}
		if(sum == N){
			printf("%5d  PERFECT\n", N);
		}
		else if(sum < N){
			printf("%5d  DEFICIENT\n", N);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}