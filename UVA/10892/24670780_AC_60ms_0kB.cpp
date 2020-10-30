#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000000

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b){
	return (ll)(a*b) / gcd(a, b);
}

vector <int> numFactor;

int total(int cou, int N){
	int sum = 0;
	for(int i = 0; i < cou; i++){
		for(int j = i; j < cou; j++){
			if(lcm(numFactor[i], numFactor[j]) == N){
//				printf("%d, %d\n", numFactor[i], numFactor[j]);
				sum++;
			}
		}
	}
	return sum;
}

int main(){
//	printf("%d\n", lcm(45, 36));
	int N;
	
//	base();
	while(1){
		scanf("%d", &N);
		if(N == 0) break;
		numFactor.clear();
		int cou = 0;
		for(int i = 1; i*i <= N; i++){
			if(N % i == 0){
//				printf("%d\n", i);
				numFactor.push_back(i);
				cou++;
				if(i*i != N){
					numFactor.push_back((N/i));
					cou++;
				}
			}
		}
//		for(int i = 0; i < cou; i++){
//			printf("	%d\n", numFactor[i]);
//		}
		
		
		printf("%d %d\n", N, total(cou, N));
	}
	
	return 0;
}