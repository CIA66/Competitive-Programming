#include<bits/stdc++.h>

#define ll long long

int main(){
	
	int n;
	scanf("%d", &n);
	int num[100006], idx = 0;
	num[idx] = n+1;
	idx++;
	for(int i = n+2; i <= 10000000; i++){
		if(idx == n) break;
		int bef = idx - 1;
		if(i % num[bef] != 0){
			num[idx] = i;
			idx++;
		}
	}
	
	for(int i = 0; i < n; i++){
		if(i == 0) printf("%d", num[i]);
		else printf(" %d", num[i]);
	}
	printf("\n");
	
	return 0;
}