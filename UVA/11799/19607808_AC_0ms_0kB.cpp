#include<stdio.h>

int main(){
	int T = 0, N = 0, c = 0, s = 0;
	scanf("%d", &T);
	for(int a=0; a<T; a++){
		scanf("%d", &N);
		s = 0;
		for(int b=0; b<N; b++){
			scanf("%d", &c);
			if(c > s) s = c;
		}
		printf("Case %d: %d\n", a+1, s);
	}
	return 0;
}