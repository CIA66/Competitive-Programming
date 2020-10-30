#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	
//	while(1){
		ll n, k;
		
		cin >> n >> k;
		
		ll id = 1, ans = 0;
		
		if(n % 2 == 0){
			
			if(k <= (n/2)){
				ans = 1 + (2 * (k-1));
			}
			else{
				k -= (n/2);
				ans = 2*k;
			}
		}
		else if(n % 2 == 1){
			if(k <= (n/2)+1){
				ans = 1 + (2 * (k-1));
			}
			else{
				k -= (n/2);
				ans = 2*(k-1);
			}
		}
		printf("%lld\n", ans);
//	}
	
	
	return 0;
}