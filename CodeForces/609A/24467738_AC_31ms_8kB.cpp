#include<bits/stdc++.h>

using namespace std;

#define ll long long 


int main(){
	
	int N, m;
	scanf("%d", &N);
	
	scanf("%d", &m);
	
	int now;
	
	priority_queue<int> pq;
	while(N--){
		scanf("%d", &now);
		pq.push(now);
	}
	
	ll sum = 0, cou = 0;
	while(!pq.empty()){
		sum += pq.top();
		cou++;
//		printf("%d\n", pq.top());
		if(sum >= m){
			printf("%lld\n", cou);
			break;
		}
		pq.pop();
	}
	
	return 0;
}