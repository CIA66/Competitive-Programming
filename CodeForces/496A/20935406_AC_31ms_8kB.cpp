#include<stdio.h>

#define inf 10000000

int min(int a, int b){
	if(a < b) return a;
	return b;
}

int max(int a, int b){
	if(a > b) return a;
	return b;
}

int main(){
	
	int N;
	int A[1006], jarak[1006];
	
	scanf("%d", &N);
	
	scanf("%d", &A[0]);
	
	int maxi = 0;
	
	for(int i=1; i<N; i++){
		
		scanf("%d", &A[i]);
		
		jarak[i-1] = A[i] - A[i-1];
		
		maxi = max(maxi, jarak[i-1]);
	}
	
	int mini = inf;
	
	for(int k=1; k<N-1; k++){
		
		mini = max( min(mini, (jarak[k] + jarak[k-1]) ), maxi );
	}
	
	printf("%d\n", mini);
	
	return 0;
}