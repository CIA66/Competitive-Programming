#include<stdio.h>

int isPrime(int N){
	
	if(N <= 1) return 0;
	for(int i=2; i<N; i++){
		if(N % i == 0) return 0;
	}
	
	return 1;
}

int bolak(int N){
	
	int temp = 0;

	while(N != 0){
		temp = (temp * 10) + (N % 10);
		N /= 10;
	}
	
	return temp;	
}

int main(){
	
	int N;
	while(scanf("%d", &N) != EOF){
//		printf("%d\n", bolak(N));
			
		int balik = bolak(N);
		int N1 = isPrime(N), N2 = isPrime(balik);
		
		if(N1 == 1 && N2 == 1){
			if(N == balik){
				printf("%d is prime.\n", N);
			}
			else printf("%d is emirp.\n", N);
		}
		else if(N1 == 1) printf("%d is prime.\n", N);
		else printf("%d is not prime.\n", N);
	}

	return 0;
}