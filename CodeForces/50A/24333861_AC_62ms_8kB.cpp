#include<bits/stdc++.h>

using namespace std;

int hasil(int M, int N){
	int a, b;
	if(M == 1) return (N / 2);
	else if(N == 1) return (M / 2);
	else if(M % 2 == 0 || N % 2 == 0){
		if(M % 2 == 0){
			return (N * (M/2));
		}
		else{
			return (M * (N/2));
		}
	}
	else{
		if(M > N){
			return ((M * (N/2)) + (M / 2));
		}
		else {
			return ((N * (M/2)) + (N / 2));
		}
	}
	
}

int main(){
	
	int M, N;
//	while(1){
	scanf("%d %d", &M, &N);
	printf("%d\n", hasil(M, N));
//	}
	return 0;
}