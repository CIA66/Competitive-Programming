#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	
	int T;
	scanf("%d", &T);
	
	for(int tc = 1; tc <= T; tc++){
		int sum = 0, a, b;
		scanf("%d", &a);
		scanf("%d", &b);
		
		for(int i = a; i <= b; i++){
			if(i % 2 == 1){
				sum += i;
			}
		}
		printf("Case %d: %d\n", tc, sum);
	}
	return 0;
}