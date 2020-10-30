#include<bits/stdc++.h>
using namespace std;
#define ll long long

int primes[10006];
void base(){
	
	primes[0] = 0;
	primes[1] = 0;
	
	for(int i = 2; i <= 10000; i++){
		primes[i] = 1;
	}
	for(int i = 2; i <= 10000; i++){
		if(primes[i] == 1){
//			printf(" -- %d\n", i);
			for(int j = i*i; j <= 10000; j+=i){
				primes[j] = 0;
			}
		}
	}
}

int hasil(int x){
	int cou = 0;
	for(int i = 1; i <= x; i++){
		if(x % i == 0) cou++;
	}
	return cou;
}

int main(){
	
	base();
	
//	for(int i = 1; i < 6; i++){
//		printf("%d : %d\n", i, hasil(i));
//	}
//	
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		int L, H;
		scanf("%d %d", &L, &H);
		int ada = 0;
		for(int k = L; k <= H; k++){
			int now = hasil(k);
			if(primes[now] == 1){
				if(ada == 0) printf("%d", k);
				else printf(" %d", k);
				ada = 1;
			}
		}
		if(ada) printf("\n");
		else printf("-1\n");
	}
	
	return 0;
}