#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second

int main(){
	
	int n, num;
	while(1){
		scanf("%d", &n);
		if(n == 0) break;
		priority_queue <int> pq;
		while(n--){
			scanf("%d", &num);
			pq.push(-num);
		}
		int sum = 0, temp = 0;
		
		temp += -pq.top();
		pq.pop();
		temp += -pq.top();
		pq.pop();
		sum += temp;
		pq.push(-temp);
		while(1){
			if(pq.size() < 2) break;
			temp = -pq.top();
			pq.pop();
			temp += -pq.top();
			pq.pop();
			sum += temp;
			pq.push(-temp);
		}
		printf("%d\n", sum);
	}
	
	return 0;
}

/*

3
1 2 3
4
1 2 3 4
0

*/