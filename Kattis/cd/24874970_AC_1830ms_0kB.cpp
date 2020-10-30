#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
	
	int N, M;
	while(1){
		
		scanf("%d %d", &N, &M);
		if(N == 0 && M == 0) break;
		
		map<int, int> mp;
		map<int, int>::iterator it;
		
		int num;
		while(N--){
			scanf("%d", &num);
			mp[num]++;
		}
		
		int cou = 0;
		while(M--){
			scanf("%d", &num);
			mp[num]++;
		}
		
		for(it = mp.begin(); it != mp.end(); it++){
			if(it->second == 2){
				cou++;
			}
		}
		printf("%d\n", cou);
		mp.clear();
	}
	return 0;
}

/*

3 3
1
2
3
1
2
4

7 1
1 4 7 10 13 16 19
16

*/