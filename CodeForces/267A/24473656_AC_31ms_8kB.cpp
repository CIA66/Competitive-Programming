#include<bits/stdc++.h>

using namespace std;

#define ll long long 

ll cek(ll a, ll b){
	
	long long count = 0;
	while(1){
		if(a <= 0 || b <= 0) break;
		
		ll temp = 0;
		if(b > a){
			temp = b / a;
			b -= a*temp;
		} 
		else {
			temp = a / b;
			a -= b*temp;
		}
		count += temp;
	}
	
	return count;
}


int main(){
	
	int N;
	long long a, b;
	
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++){
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", cek(a, b));
	}
	
	
	return 0;
}