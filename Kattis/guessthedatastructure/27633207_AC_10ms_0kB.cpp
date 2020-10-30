#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int cm, x;
	while(scanf("%d", &n) != EOF){
		
		int valSt = 1, valQu = 1, valPq = 1;
		stack <int> st;
		queue <int> q;
		priority_queue <int> pq;
		
		while(n--){
			scanf("%d %d", &cm, &x);
			if(cm == 1){
				st.push(x);
				q.push(x);
				pq.push(x);
			}
			else{
				if(st.empty() || st.top() != x){
					valSt = 0;
					
				}
				if(q.empty() || q.front() != x){
					valQu = 0;
					
				}
				if(pq.empty() || pq.top() != x){
					valPq = 0;
				}
				if(!st.empty()) st.pop();
				if(!q.empty()) q.pop();
				if(!pq.empty()) pq.pop();
			}
		}
		if(valSt == 1 && valQu == 0 && valPq == 0){
			printf("stack\n");
		}
		else if(valSt == 0 && valQu == 1 && valPq == 0){
			printf("queue\n");
		}
		else if(valSt == 0 && valQu == 0 && valPq == 1){
			printf("priority queue\n");
		}
		else if(valSt == 0 && valQu == 0 && valPq == 0){
			printf("impossible\n");
		}
		else{
			printf("not sure\n");
		}
	}
	return 0;
}