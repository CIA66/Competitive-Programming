#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll ans[100];

void base(){
	
	ans[1] = 2;
	ans[2] = 3;
	for(int i = 3; i < 51; i++){
		ans[i] = ans[i-1] + ans[i-2];
	}
}
int main(){
	
	base();
	int N;
	
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++){
		int x;
		scanf("%d", &x);
		printf("Scenario #%d:\n", i+1);
		printf("%lld\n", ans[x]);
		printf("\n");
	}
	return 0;
}

