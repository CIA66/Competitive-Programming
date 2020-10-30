#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define inf 100000000

void loop(ll n){
	
	ll cou = 0;
	
	while(n > 1){
		if(n % 2 == 0){
			n = n / 2;
		}
		else{
			n = 3 * n + 3;
		}
		cou++;
		if(cou > inf){
			printf("NIE\n");
			break;
		}
	}
	if(cou < inf) printf("TAK\n");
}

int main(){
	
	ll n;
	scanf("%lld", &n);
	loop(n);
	return 0;
}
