#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll H(int n){
	
	if(n < 1) return 0;
	
	ll res = 0;
	ll num = 0, now, bef = -1;
	ll len = (ll)sqrt(n);
//	printf(" len %lld\n", len);
	
	for(ll i = 1; i <= len; i++){
		now = (n / i);
		
		if(bef != -1) res += num*(bef - now);
		res += now;
		
		bef = now;
		num++;
//		printf("%d ", res);
//		printf("%d ", now);
	}
	res += len* (now - len);
	
//	printf("\n");

	return res;
}

int main(){
	
//	for(int i = 1; i <= 100; i++){
//		printf("-- %d %lld --\n", i, H(i));
//	}
	
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		printf("%lld\n", H(n));
	}
	return 0;
}