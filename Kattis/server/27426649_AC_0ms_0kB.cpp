#include<bits/stdc++.h>
using namespace std;

int n, T, x, tot[56];

int main(){
	
	scanf("%d %d", &n, &T);
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		tot[i] = tot[i-1] + x;
	}
	int ada = 0;
	for(int i = 1; i <= n; i++){
		if(tot[i] > T){
			printf("%d\n", i-1);
			ada = 1;
			break;
		}
	}
	if(ada == 0) printf("%d\n", n);
	
	return 0;
}