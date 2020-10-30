#include<bits/stdc++.h>

using namespace std;
#define inf 1000000
#define ll long long

int main(){
	
	ll a, b;
//	printf("%lld\n", 45736876540 - 23487654097);
	while(scanf("%lld %lld", &a, &b) == 2){
		ll temp = 0;
		if(a > b) {
			temp = a - b;
		}
		if(b > a){
			temp = b - a;
		}
		printf("%lld\n", temp);
		
	}
	
	return 0;
}