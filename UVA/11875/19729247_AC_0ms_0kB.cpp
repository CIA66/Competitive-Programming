#include<stdio.h>

int main(){
	int T = 0, N = 0;
	scanf("%d", &T);
	for(int a=1; a<=T; a++){
		int list[13] = {0};
		scanf("%d", &N);
		for(int b=0; b<N; b++){
			scanf("%d", &list[b]);
		}
		printf("Case %d: %d\n", a, list[N/2]);
		
	}
	return 0;
}