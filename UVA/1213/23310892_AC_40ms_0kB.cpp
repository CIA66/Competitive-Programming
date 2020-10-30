#include<stdio.h>

int prime[2000];
int vPrime[2000];

int primeBase(int N){
	
	for(int i = 0; i <= N; i++){
		prime[i] = 1;
	}
	
	for(int i = 2; i*i <= N; i++){
		if(prime[i] == 1){
			
			for(int j = i*i; j <= N; j+=i){
				prime[j] = 0;
			}
		}
	}
	
	int idx = 0;
	for(int i = 2; i <= N; i++){
		if(prime[i] == 1){
			vPrime[idx] = i;
			idx++;
		} 
	}

	return idx;
}

int dp[1200][16];

void ans(int idx, int M, int N){
	
	for(int i = 0; i <= M; i++){
		for(int j = 0; j <= N; j++){
			dp[i][j] = 0;
		}
	}
	
	dp[0][0] = 1;

	for(int p = 0; p < idx; p++){
		
		int now = vPrime[p];
		if(now > M) break;
		for(int i = M-now; i >= 0; i--){
			for(int j = N-1; j >= 0; j--){
			
				if(dp[i][j] != 0){
					dp[i+now][j+1] += dp[i][j];
				}
			}
		}
		
//		printf("-- %d -- %d --\n", p, now);
//		for(int i = 0; i <= M; i++){
//			for(int j = 0; j <= N; j++){
//				printf("%4d", dp[i][j]);
//			}
//			printf("\n");
//		}
	}
	printf("%d\n", dp[M][N]);
}

int main(){
	
	int N = primeBase(1120);
	
//	printf("%d\n", N);
	
//	for(int i = 0; i < N; i++){
//		printf("%d ", vPrime[i]);
//	}
	
	int n, k;
	
	while(1){
		scanf("%d %d", &n, &k);
		
		if(n == 0 && k == 0) break;
		
		ans(N, n, k);
	}
	
	return 0;
}


/*

24 3
24 2
2 1
1 1
4 2
18 3
17 1
17 3
17 4
100 5
1000 10
1120 14
0 0

*/