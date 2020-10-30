#include<stdio.h>
#include<string.h>

int f91(int N){
	if(N <= 100) {
		return f91(f91(N + 11));
	}
	if(N >= 101){
		return N - 10;
	}
}

int main(){
	int N = 0;
	while(1){
		scanf("%lld", &N);
		if(N == 0) break;
		printf("f91(%d) = %d\n", N, f91(N));
	}
	
	return 0;
}