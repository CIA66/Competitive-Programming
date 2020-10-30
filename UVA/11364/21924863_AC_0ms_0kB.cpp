#include<bits/stdc++.h>

using namespace std;
#define inf 1000000
#define ll long long

int main(){
	
	int T;
	scanf("%d", &T);
	
	for(int tc = 1; tc <= T; tc++){
		int N;
		scanf("%d", &N);
		
		int a;
		int mini = inf, maxi = 0;
		for(int i = 0; i < N; i++){
			scanf("%d", &a);
			if(a < mini) mini = a;
			if(a > maxi) maxi = a;
		}
		printf("%d\n", (maxi - mini) * 2);
	}
	return 0;
}