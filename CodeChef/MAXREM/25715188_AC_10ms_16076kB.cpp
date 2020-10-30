#include<bits/stdc++.h>

using namespace std;
#define ll long long


int main(){
	
	int N, A, maxi1, maxi2;
	
	priority_queue <int> pq;
	
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &A);
		pq.push(A);
	}
	
	int cou = 0;
	while(!pq.empty()){
//		printf("%d\n", pq.top());
		if(cou == 0) {
			maxi1 = pq.top();
			cou++;
		}
		if(cou == 1){
			maxi2 = pq.top();
			if(maxi2 != maxi1){
				cou++;
			}
		}
		if(cou == 2) break;
		pq.pop();
	}
//	printf("%d %d\n", maxi1, maxi2);
	if(maxi1 == maxi2) printf("%d\n", 0);
	else{
		printf("%d\n", maxi2);
	}
	return 0;
}