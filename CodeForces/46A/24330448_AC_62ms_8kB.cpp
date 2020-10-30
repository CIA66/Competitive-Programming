#include<bits/stdc++.h>

using namespace std;


int main(){
	
	int N, tc;
	scanf("%d", &N);
	tc = N;
	tc--;
	int now = 1, plus = 1;
	
	now += plus;
	plus += 1;
	printf("%d", now);
	tc--;
		
	while(tc--){
//		printf("%d %d\n", now, plus);
		now += plus;
		if(now > N){
			now = now % N;	
		}
		plus += 1;
		printf(" %d", now);
	}
	printf("\n");
	return 0;
}