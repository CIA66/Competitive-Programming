#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll f(ll N){
	
	ll sum = 0;
	while(N > 0){
		sum += (N % 10);
		N /= 10;
	}
	return sum;
}

ll g(ll N){
	
	while(N >= 10){
		N = f(N);
	}
	return N;
}

int main(){
	
	ll N;
	while(1){
		scanf("%lld", &N);
		if(N == 0) break;
		printf("%d\n", g(N));
	}
	
	return 0;
}