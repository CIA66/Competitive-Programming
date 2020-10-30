#include<bits/stdc++.h>

using namespace std;

#define ll long long

int primes[10000006];
vector<int> vprimes;

void base(){
	
	primes[0] = 1;
	primes[1] = 1;
	
	for(ll i = 2; i <= 10000000; i++){
		if(primes[i] == 0){
//			printf(" -- %lld\n", i);
			vprimes.push_back(i);
			
			for(ll j = i*i; j <= 10000000; j+=i){
				primes[j] = 1;
			}
		}
	}
}

int main(){
	
	base();
//	printf("%d\n", vprimes.size());
//	printf("%d\n", vprimes[664578]); 9999991
	
	int n;
	scanf("%d", &n);
	
	int i = 0, now = vprimes[i], valid = 0;
	int a, b;
	
	while(now < n){
		if(primes[n-now] == 0){
			printf("%d %d\n", now, n-now);
			valid = 1;
			break;
		}
		i++;
		now = vprimes[i];
	}
	
	if(valid == 0) printf("-1\n");
	
	return 0;
}