#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	
	int N;
	scanf("%d", &N);
	ll X[100006];
	for(int i = 0; i < N; i++){
		scanf("%lld", &X[i]);
	}
	for(int i = 0; i < N; i++){
		ll mini, maxi;
		if(i == 0){
			mini = X[1] - X[0];
			maxi = X[N-1] - X[0];
		}
		else if(i == N-1){
			mini = X[N-1] - X[N-2];
			maxi = X[N-1] - X[0];
		}
		else{
			ll a, b;
			a = X[i] - X[0];
			b = X[N-1] - X[i];
			if(a > b) maxi = a;
			else maxi = b;
			a = X[i] - X[i-1];
			b = X[i+1] - X[i];
			if(a < b) mini = a;
			else mini = b;
		}
		printf("%lld %lld\n", mini, maxi);
	}
	
	return 0;
}