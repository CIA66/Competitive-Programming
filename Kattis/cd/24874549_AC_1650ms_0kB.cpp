#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
	
	ll N, M;
	set<ll> s;
	while(1){
		scanf("%lld %lld", &N, &M);
		if(N == 0 && M == 0) break;
		ll sum = N + M;
		s.clear();
		ll num;
		while(N--){
			scanf("%lld", &num);
			s.insert(num);
		}
		ll cou = 0;
		while(M--){
			scanf("%lld", &num);
			if(s.find(num) != s.end()){
				cou++;
			}
		}
		printf("%lld\n", cou);
	}
	return 0;
}

/*

3 3
1
2
3
1
2
4

7 1
1 4 7 10 13 16 19
16

*/