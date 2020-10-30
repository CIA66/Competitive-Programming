#include<bits/stdc++.h>

using namespace std;

#define ll long long 


int main(){
	
	int n, k;
	scanf("%d %d", &n, &k);
	
	int now[60], plus = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &now[i]);
	}
	
	if(now[k] == 0){
		plus = k-1;
		for(int i = plus; i > 0; i--){
			if(now[i] == 0){
				plus--;
			}
		}
		printf("%d\n", plus);
	}
	else{
		plus = k;
		for(int i = k+1; i <= n; i++){
			if(now[i] == now[k]){
				plus++;
			}
		}
		printf("%d\n", plus);
	}
	
	

	return 0;
}