#include<bits/stdc++.h>

using namespace std;
#define inf 1000000
#define ll long long

int main(){
	int tc = 1;
	while(1){
		int T;
		scanf("%d", &T);
		if(T == 0) break;
		int a = 0, b = 0;
		for(int i = 1; i <= T; i++){
			int N;
			scanf("%d", &N);
			if(N == 0) b++;
			else a++;
		}
		printf("Case %d: %d\n", tc++, a-b);
	}
	
	return 0;
}