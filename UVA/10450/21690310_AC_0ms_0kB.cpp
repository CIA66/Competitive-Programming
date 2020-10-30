#include<stdio.h>

#define MAXN 50
#define ll long long

void generate(ll ans[]){
	
	ans[0] = 0;
	ans[1] = 2;
	ans[2] = 3;
	
	for(int i = 3; i <= MAXN; i++){
		ans[i] = ans[i-1] + ans[i-2];
	}
}

int main(){
	
	ll ans[56] = {0};

	generate(ans);
	
	int T;
	
	scanf("%d", &T);
	
	for(int tc = 1; tc <= T; tc++){
		
		int n;
		scanf("%d", &n);

		printf("Scenario #%d:\n", tc);
		printf("%lld\n", ans[n]);
		printf("\n");
	}
	return 0;
}