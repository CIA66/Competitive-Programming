#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll mod(ll x, ll y, ll n){
	if(y == 0) return 1;
	else if(y % 2 == 0) return (mod(x, y / 2, n) % n * mod(x, y / 2, n) % n) % n;
	else if(y % 2 == 1) return (x % n* mod(x, y / 2, n) % n * mod(x, y / 2, n) % n) % n;
}

int main(){
	
	int T;
	while(1){
		
		scanf("%d", &T);
		if(T == 0) break;
		
		ll x, y, n;
		
		for(int i = 0; i < T; i++){
			scanf("%lld %lld %lld", &x, &y, &n);
			
			printf("%lld\n", mod(x, y, n));
		}
		
	}
	
	return 0;
}