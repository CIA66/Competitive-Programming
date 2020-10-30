#include<bits/stdc++.h>

using namespace std;

#define ll long long 


int main(){
	
	int T;
	scanf("%d", &T);
	
	int N;
	for(int tc = 1; tc <= T; tc++){
		scanf("%d", &N);
		int now, before = 0;
		int high = 0, low = 0;
		scanf("%d", &now);
		before = now;
		for(int i = 1; i < N; i++){
			scanf("%d", &now);
			if(now > before){
				high++;
				before = now;
			}
			else if(now < before){
				low++;
				before = now;
			}
		}

		printf("Case %d: %d %d\n", tc, high, low);
	}
	return 0;
}

/*

3
8
1 4 2 2 3 5 3 4
1
9
5
1 2 3 4 5

*/