#include<stdio.h>

int main(){
	int T = 0;
	scanf("%d", &T);
	for(int a=1; a<=T; a++){
		int N = 0, K = 0, P = 0;
		scanf("%d %d %d", &N, &K, &P);
		
		while(P > 0){
//			printf("%d ", K);
			if(K == N){
				K = 1;
			}
			else {
				K++;
			}
			P--;
		}
		printf("Case %d: %d\n", a, K);
	}
	return 0;
}