#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define MAXN 1000000
int primes[MAXN+10];
void sieve(){
	
	for(int i = 0; i <= MAXN; i++){
		primes[i] = 1;
	}
	primes[0] = 0; primes[1] = 0;
	for(int i = 2; i*i <= MAXN; i++){
		
		if(primes[i] == 1){
			for(int j = i*i; j <= MAXN; j+=i){
				primes[j] = 0;
			}
		}
	}
}

int rev(int N){
	int num = 0;
	while(N != 0){
		num = num*10 + (N % 10);
		N /= 10;
	}
	return num;
}

int main(){
	sieve();
	int N;
	while(scanf("%d", &N) != EOF){
		int NN = rev(N);
		if(primes[N] == 0) printf("%d is not prime.\n", N);
		else if(primes[N] == 1 && primes[NN] == 0) printf("%d is prime.\n", N);
		else if(primes[N] == 1 && primes[NN] == 1 && NN == N) printf("%d is prime.\n", N);
		else printf("%d is emirp.\n", N);
	}
	
	return 0;
}