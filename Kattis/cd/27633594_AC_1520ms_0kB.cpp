#include<bits/stdc++.h>

using namespace std;


int main(){
	
	int n, m;
	while(1){
		scanf("%d %d", &n, &m); getchar();
		if(n == 0 && m == 0) break;
		map<int, int> mymap;
		int x;
		for(int i = 0; i < n; i++){
			scanf("%d", &x); getchar();
			mymap[x] = 1;
		}
		int cou = 0;
		for(int i = 0; i < m; i++){
			scanf("%d", &x); getchar();
			if(mymap[x] == 1){
				cou++;
			}
		}
		
		printf("%d\n", cou);
	}
	
	return 0;
}