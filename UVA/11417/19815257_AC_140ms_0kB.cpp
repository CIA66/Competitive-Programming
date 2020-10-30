#include<stdio.h>

// Euclid's algorithm
int GCD(int a, int b){
	if(b == 0) return a;
	return GCD(b, a%b);
}

int main(){
	int N = 0;
	while(1){
		scanf("%d", &N);
		if(N == 0) break;
		
		int G = 0, i = 0, j = 0;
		for(i = 1; i<N; i++){
			for(j = i+1; j<=N; j++){
				G += GCD(i, j);
			}
		}
		
		printf("%d\n", G);
	}
	return 0;
}