#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000000

int main(){
	
	int T;
	scanf("%d", &T);
	while(T--){
		int N, mini = inf;
		scanf("%d", &N);
		for(int i = 1; i*i <= N; i++){
			if(N % i != 0) continue;
			int j = N / i;
			if(i == j) {
				mini = 0;
				break;
			}
			else{
				int k = j - i;
//				printf("%d %d\n", i, j);
				if(k < mini){
					mini = k;
				}
			}
		}
		printf("%d\n", mini);
	}
	
	return 0;
}