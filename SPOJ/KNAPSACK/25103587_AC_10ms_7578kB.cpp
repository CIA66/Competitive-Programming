#include<bits/stdc++.h>
using namespace std;
#define ll long long

int knapSack(int W, int wt[], int val[], int n){
	
	int K[n+1][W+1];
	
	for(int i = 0; i <= n; i++){
		for(int w = 0; w <= W; w++){
			if(i == 0 || w == 0){
				K[i][w] = 0;
			}
			else if(wt[i-1] <= w)
				K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
			else
				K[i][w] = K[i-1][w];
		}
	}
	return K[n][W];
}


int main(){
	
	int val[2006], wt[2006];
	int S, N;
	
	scanf("%d %d", &S, &N);
	
	for(int i = 0; i < N; i++){
		scanf("%d %d", &wt[i], &val[i]);
	}
	
	printf("%d\n", knapSack(S, wt, val, N));

	return 0;
}