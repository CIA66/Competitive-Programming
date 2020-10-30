#include<stdio.h>

int main(){
	long long int A = 0, L = 0, terms = 0, count = 0, tc = 1;
	while(scanf("%lld %lld", &A, &L) != EOF){
		long long int asli = A;
		count = 0;
		if(A < 0 && L < 0) break;
		while(A <= L){
			count++;
			if(A == 1){
				break;
			}
			else if(A % 2 == 0){
				A /= 2;
			}
			else if(A % 2 == 1){
				A = 3 * A + 1;
			}
		}
		printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n", tc, asli, L, count);
		tc++;
	}
	
	return 0;
}