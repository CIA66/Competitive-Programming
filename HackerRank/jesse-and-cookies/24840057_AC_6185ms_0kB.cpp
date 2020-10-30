#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back

int main(){
	int N, K;
	
	scanf("%d %d", &N, &K);
	
	priority_queue <int> pq;
	int num;
	while(N--){
		scanf("%d", &num);
		pq.push(-num);
	}
//	printf(" size ; %d\n", pq.size());
	int temp, cou = 0;
	while(pq.size() >= 2){
//		printf("top : %d\n", -pq.top());
		if(-pq.top() >= K) break;

		cou++;
		temp = -pq.top();
		pq.pop();
//		printf("top : %d\n", -pq.top());
		temp += (2 * -pq.top());
		pq.pop();
		pq.push(-temp);
	}
	
	if(-pq.top() >= K) printf("%d\n", cou);
	else printf("-1\n");
	
	return 0;
}

/*

6 7
1 2 3 9 10 12

*/