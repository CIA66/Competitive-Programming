#include<bits/stdc++.h>
using namespace std;
#define ll long long

int count(int S[], int m, int n){
	
	int table[n+1];
	
	memset(table, 0, sizeof(table));
	
//	for(int i = 0; i < m; i++){
//		table[0][i] = 1;
//	}
	table[0] = 1;
	
//	for(int i = 1; i <= m; i++){
//		for(int j = 1; j <= n; j++){
//			if(S[i-1] > j){
//				table[i][j] = table[i-1][j];
//			}
//			else{
//				table[i][j] = table[i-1][j] + table[i][j-(i-1)];
//			}
//		}
//	}
//	
//	return table[m][n];
	
	for(int i = 0; i < m; i++){
		for(int j = S[i]; j <= n; j++){
			table[j] += table[j-S[i]];
		}
	}
	return table[n];
}

int main(){
	
	int arr[] = {50, 25, 10, 5, 1};
	
	int m = sizeof(arr)/sizeof(arr[0]);
	int n;
	
	while(scanf("%d", &n) != EOF){
		printf("%d\n", count(arr, m, n));
	}
	
	
	return 0;
}