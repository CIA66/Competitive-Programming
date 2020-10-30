#include<stdio.h>

int main(){
	int B = 0, N = 0;
	int R[22] = {0};
	while(1){
		scanf("%d %d", &B, &N);
		if(B == 0 && N == 0) break;
		for(int a = 1; a <= B; a++){
			scanf("%d", &R[a]);
		}
		
		int D = 0, C = 0, V = 0;
		for(int b=1; b<=N; b++){
			scanf("%d %d %d", &D, &C, &V);
			R[D] -= V;
			R[C] += V;
		}
		
		int bisa = 1;
		for(int j=1; j<=B; j++){
			if(R[j] < 0){
				bisa = 0;
				break;
			}
		}
		if(!bisa) printf("N\n");
		else printf("S\n");
	}
	
	return 0;
}