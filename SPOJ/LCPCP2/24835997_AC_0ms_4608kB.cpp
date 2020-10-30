#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll sisa(ll b, ll e, ll m){
	ll res = 1;
	
	b = b % m;
	
	while(e > 0){
		
		if(e & 1){
			res = (res * b) % m;
		}
		e = e >> 1; // y = y/2
		b = (b * b) % m;
		
	}
	
	return res;
}

int main(){
	
	int T;
	scanf("%d", &T);
	ll b, e, m, c;
	for(int tc = 1; tc <= T; tc++){
		scanf("%lld %lld %lld", &b, &e, &m);
		c = sisa(b, e, m);
		printf("%d. %lld\n", tc, c);
	}
	
	
	return 0;
}