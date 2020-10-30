#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second

int main(){
	
	int T;
	scanf("%d", &T);
	
	int cm, n;
	
	queue <int> q;
	while(T--){
		scanf("%d", &cm);
		if(cm == 1){
			scanf("%d", &n);
			q.push(n);
		}
		else if(cm == 2){
			if(!q.empty())
				q.pop();
		}
		else{
			if(q.empty()) printf("Empty!\n");
			else printf("%d\n", q.front());
		}
	}
	return 0;
}

/*

6
1 5
1 6
2
3
2
3

*/