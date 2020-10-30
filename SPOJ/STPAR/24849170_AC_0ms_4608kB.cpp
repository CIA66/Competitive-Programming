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
		queue <int> qS;
		queue <int> qE;
		stack <int> st;
		
		while(n--){
			scanf("%d", &num);
			qS.push(num);
		}
		int i = 1;
		while(!qS.empty() && qS.front() == i){
			qE.push(qS.front());
			qS.pop();
			i++;
		}
		if(!qS.empty()){
			st.push(qS.front());
			qS.pop();
		}
			
			while(!qS.empty()){
				if(qS.front() == i){
					qE.push(qS.front());
					qS.pop();
					i++;
				}
				else if(!st.empty() && st.top() == i){
					qE.push(st.top());
					st.pop();
					i++;
				}
				else{
					st.push(qS.front());
					qS.pop();
				}
			}
			while(!st.empty()){
				if(st.top() == i){
					qE.push(st.top());
					st.pop();
					i++;
				}
				else{
					break;
				}
			}
			
		if(qS.empty() && st.empty()){
			printf("yes\n");
		}
		else if(qS.empty() && !st.empty()){
			printf("no\n");
		}	
//		printf("test  %d - %d - %d\n", qS.size(), st.size(), qE.size());
		while(!qE.empty()){
//			printf("%d ", qE.front());
			qE.pop();
		}
		while(!st.empty()){
			st.pop();
		}
//		printf("\n");
	}
	
	return 0;
}

/*

5
5 1 2 4 3
5
3 1 2 5 4
0


*/