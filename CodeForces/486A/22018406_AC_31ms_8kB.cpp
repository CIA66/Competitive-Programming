#include<bits/stdc++.h>

#define ll long long

int main(){
	ll x;
	scanf("%lld", &x);
	
	ll sumOdd, sumEven;
	
	ll Un = x, n;
	
	// genap
	n = Un / 2;
	sumEven = n*n + n;
	
	
	// ganjil
	n = (Un + 1) / 2;
	sumOdd = n * n;
	
	printf("%lld\n", sumEven - sumOdd);
	
	return 0;
}