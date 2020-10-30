#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back

int main(){
	int N;
	
	while(1){
		scanf("%d", &N);
		if(N == 0) break;
		
		queue <int> q;
		int num = 1;
		while(N--){
			q.push(num);
			++num;
		}
		
		int star = 1;
		printf("Discarded cards:");
		while(q.size() >= 2){
			if(star == 1){
				printf(" %d", q.front());
				star = 0;
			}
			else printf(", %d", q.front());
			q.pop();
			q.push(q.front());
			q.pop();
		}
		printf("\n");
		printf("Remaining card: %d\n", q.front());
		q.pop();
	}
	
	return 0;
}

/*

7
19
10
6
0

*/