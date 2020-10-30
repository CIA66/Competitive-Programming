#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int t;
	scanf("%d", &t);
	
	int n, p;
	while(t--){
		scanf("%d %d", &n, &p);
		int len = 2*n + p;
		int cou = 0, done = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				if(cou == len){
					done = 1;
					break;
				}
				printf("%d %d\n", i, j);
				cou++;
			}
			if(done == 1){
				break;
			}
		}
	}
	
	return 0;
}