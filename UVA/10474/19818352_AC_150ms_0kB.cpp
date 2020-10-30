#include<stdio.h>

int main(){
	int list[10006];
	int N = 0, Q = 0;
	int tc = 1;
	
	while(1){
		scanf("%d %d", &N, &Q);
		if(N == 0 && Q == 0) break;
		
		for(int a=0; a<10001; a++){
			list[a] = 0;
		}
		int temp = 0;
		for(int b=0; b<N; b++){
			scanf("%d", &temp);
			list[temp]++;
		}
		
		printf("CASE# %d:\n", tc++);
		int key = 0;
		for(int c=0; c<Q; c++){
			scanf("%d", &key);
			if(list[key] > 0){
				int idx = 1;
				for(int d=1; d<key; d++){
					idx += list[d];
				}
				printf("%d found at %d\n", key, idx);
			}
			else printf("%d not found\n", key);
		}
	}
	return 0;
}