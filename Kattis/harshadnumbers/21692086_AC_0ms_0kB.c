#include<stdio.h>

int sum(int N){
	
	int summ = 0;
	
	while(N != 0){
		summ += (N % 10);
		N /= 10;
	}
	return summ;
}

int main(){
	
	int N;
	scanf("%d", &N);

	while(1){
		if(N % sum(N) == 0){
			printf("%d\n", N);
			break;
		}
		N++;
	}
	
	return 0;
}
