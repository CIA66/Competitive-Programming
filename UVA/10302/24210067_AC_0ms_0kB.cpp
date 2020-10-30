#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	
	ll N;
	while(scanf("%lld", &N) != EOF){
		printf("%lld\n", ( (N*N) * (N+1) * (N+1) ) / 4);
	}
	return 0;
}