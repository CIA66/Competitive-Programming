#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define inf 100000000

int main(){
	
	int n;
	scanf("%d", &n);
	
	int T[106];
	for(int i = 1; i <= n; i++){
		scanf("%d", &T[i]);
	}
	
	int maxi = 0, mini = inf, d = 0;
	
	for(int k = 2; k < n; k++){
		maxi = 0;
		for(int i = 2; i < n; i++){
			if(i == k){
				d = T[i+1] - T[i-1];
				maxi = max(maxi, d);
//				printf("-- %d\n", d);
			}
			else{
				d = T[i+1] - T[i];
				maxi = max(maxi, d);
//				printf("%d\n", d);
			}
		}
//		printf("\nmaxi : %d\n", maxi);
		mini = min(mini, maxi);
//		printf("mini : %d\n", mini);
	}
	printf("%d\n", mini);
	
	return 0;
}

/*
5
1 2 3 7 8
*/