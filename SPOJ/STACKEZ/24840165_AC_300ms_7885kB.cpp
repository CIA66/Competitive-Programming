#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second

int main(){
	
	int T;
	scanf("%d", &T);
	
	int cm, n;
	
	stack <int> st;
	while(T--){
		scanf("%d", &cm);
		if(cm == 1){
			scanf("%d", &n);
			st.push(n);
		}
		else if(cm == 2){
			if(!st.empty())
				st.pop();
		}
		else{
			if(st.empty()) printf("Empty!\n");
			else printf("%d\n", st.top());
		}
	}
	return 0;
}

/*

6
1 15
1 20
2
3
2
3

*/