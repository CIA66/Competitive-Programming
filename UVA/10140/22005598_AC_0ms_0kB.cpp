// Acc :)

#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define MAXN 1000006
#define inf 2147483647


void simpleSieve(ll limit, vector<ll> &vPrime){
	
//	bitset<MAXN> bPrime;
	bool bPrime[MAXN];
	
//	bPrime.set();
	memset(bPrime, true, sizeof(bPrime));
	
	
	bPrime[0] = 0;
	bPrime[1] = 0;
	
	for(ll i = 2; i <= limit; i++){
		
		if(bPrime[i] == 1){
			vPrime.push_back(i);
			
			for(ll j = i*i; j <= limit; j += i){
				bPrime[j] = 0;
			}
		}
	}
}


void primeInRange(ll low, ll high){
	
	int limit = floor(sqrt(high)) + 1;
	
	vector<ll> vPrime;
	simpleSieve(limit, vPrime);
	
	int n = high - low + 1;
	
	bool mark[n+1];
	memset(mark, true, sizeof(mark));
	
	
	for(int i = 0; i < vPrime.size(); i++){
		
		ll angkaTerdekatLow = floor(low / vPrime[i]) * vPrime[i];
		
		if(angkaTerdekatLow < low){
			angkaTerdekatLow += vPrime[i];
		}
		if(angkaTerdekatLow == vPrime[i]){
			angkaTerdekatLow += vPrime[i];
		}
		
		for(ll j = angkaTerdekatLow; j <= high; j+= vPrime[i]){
			mark[j-low] = false;
		}
	}
	
	ll curr = -1, mini = inf, maxi = 0, valid = 0;
	pair <ll, ll> minPair; pair <ll, ll> maxPair;
	
	for(int i = low; i <= high; i++){
		if(mark[i - low] && i != 0 && i != 1){
			if(curr != -1){
				valid = 1;
				ll temp = i - curr;
				if(temp < mini){
					mini = temp;
					minPair.first = curr, minPair.second = i;
				}
				if(temp > maxi){
					maxi = temp;
					maxPair.first = curr, maxPair.second = i;
				}
			}
			curr = i;
		}
	}
	
	if(!valid){
		printf("There are no adjacent primes.\n");
	}
	else{
		printf("%lld,%lld are closest, %lld,%lld are most distant.\n", minPair.first, minPair.second, maxPair.first, maxPair.second);
	}
	
}

int main(){
//	vector<ll> vvPrime;
//	simpleSieve(50000, vvPrime);
//	printf("%d\n", vvPrime.size());
	
	ll L, U;
	while(scanf("%lld %lld", &L, &U) == 2){
		
		primeInRange(L, U);
		
	}
	
	return 0;
}


/*
	// masih blm bisa tapi udah acc :')
2147483647 2147483647
2146483647 2147483647
1 2
1 10
2 3
2 10
1 1000001
550 9214
500000 1500000
4 5
4 7
5 7
5 5
5 6
1500000 1500001
1500000 1500000
1500006 1500019
1500006 1500018
1500007 1500018
1500007 1500019
1500008 1500019
1500008 1500018


*/