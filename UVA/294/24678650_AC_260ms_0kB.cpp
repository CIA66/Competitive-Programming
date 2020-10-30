#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll hasil(ll x){
	ll cou = 0;
	for(ll i = 1; i*i <= x; i++){
		if(x % i == 0){
			cou++;
			if(i*i != x) cou++;
		}
	}
	return cou;
}

int main(){
	
//	for(int i = 1; i <= 10; i++){
//		printf("%lld : %lld\n", i, hasil(i));
//	}
//	printf("%d : %d\n", 16, hasil(16));
//	printf("%lld : %lld\n", 999999924, hasil(999999924));

	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		ll L, H;
		scanf("%lld %lld", &L, &H);
		ll maxi = 0, numMax = 0;
		for(int k = L; k <= H; k++){
			ll now = hasil(k);
			if(now > maxi){
				numMax = k;
				maxi = now;
			}
		}
		printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n", L, H, numMax, maxi);
	}
	
	return 0;
}