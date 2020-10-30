#include<bits/stdc++.h>

using namespace std;
#define inf 1000000
#define ll long long

int main(){
	
	int T;
	scanf("%d", &T);
	
	for(int tc = 1; tc <= T; tc++){
		
		int N;
		scanf("%d", &N);
		
		int block[56], naik = 0, turun = 0;
		if(N != 0){
			int temp = 0;
			
			scanf("%d", &block[0]);
			for(int i = 1; i < N; i++){
				scanf("%d", &block[i]);
				temp = block[i] - block[i-1];
				if(temp > 0){
					naik++;
				}
				else if(temp < 0){
					turun++;
				}
			}
		}
		printf("Case %d: %d %d\n", tc, naik, turun);
	}
	
	return 0;
}