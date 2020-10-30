#include<bits/stdc++.h>

using namespace std;

#define ll long long 



int main(){
	
	double N;
	scanf("%lf", &N);
	ll akar = (ll) sqrt(N);
	ll sum = 0, xtra = 0;
	if(akar*akar == (ll)N) printf("%lld\n", akar*4);
	else{
		sum += (akar * 4);
		xtra = (ll)N - (akar*akar);
//		printf("--%lld\n", xtra);
		if(xtra <= akar) sum += 2;
		else sum += 4;
		printf("%lld\n", sum);
	}
	
	
	return 0;
}

/*


*/