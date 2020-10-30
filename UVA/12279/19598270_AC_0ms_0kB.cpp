#include<stdio.h>

int main(){
	int N = 0;
	int X = 1, Y = 0;
	int now = 0;
	while(1){
		scanf("%d", &N);
		if(N == 0) break;
		int supposed = 0, actually = 0;
		for(int a=0; a<N; a++){
			scanf("%d", &now);
			if(now == 0){
				actually++;
			} else {
				supposed++;
			}
		}
		Y = supposed - actually;
		printf("Case %d: %d\n", X, Y);
		X++;
	}
	return 0;
}