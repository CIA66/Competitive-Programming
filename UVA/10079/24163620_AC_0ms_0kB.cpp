#include<stdio.h>

int main(){
	
	long long N, hasil;
	while(1){
		scanf("%lld", &N);
		if(N < 0) break;
		hasil = N * ( N + 1 ) / 2 + 1;
		printf("%lld\n", hasil);
	}
	
	return 0;
}

/*

5
10
-100

210000000

*/