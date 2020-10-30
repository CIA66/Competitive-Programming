#include<bits/stdc++.h>

using namespace std;


int main(){
	char asdasd[100];
	int w, p;
	scanf("%d %d", &w, &p);
	priority_queue<int> pq;
	
	int key[106];
	for(int i = 0; i < p; i++){
		scanf("%d", &key[i]);
		pq.push(-key[i]);
	}
	
	int idx = 0, ans[10006];
	for(int k = p; k >= 0; k--){
		for(int l = k-1; l >= -1; l--){
			if(k == p){
				pq.push(-(w - key[l]));
			}
			else if(l == -1){
				pq.push(-(key[0] - 0));
			}
			else{
				pq.push(-(key[k] - key[l]));
			}
			idx++;
		}
	}
	
	int bef = -1;
	while(!pq.empty()){
		if(bef == -1){
			printf("%d ", -pq.top());
			bef = -pq.top();
		}
		else{
			if(-pq.top() != bef){
				printf("%d ", -pq.top());
				bef = -pq.top();
			}
		}
		pq.pop();
	}
	printf("\n");
	return 0;


}