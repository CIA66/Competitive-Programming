#include<stdio.h>

int re(int count, int N){
	
//	printf("%d ", N);
	if(N == 1) return count;
	count++;
	if (N % 2 == 1) {
		N = 3 * N + 1;
		return re(count, N);
	} else {
		N /= 2;
		return re(count, N);
	}
}

int main(){
	int N = 0, j = 0 ;
	while(scanf("%d %d", &N, &j) != EOF){
		
		int count = 1, final = 0, max = 0;
		if(N > j){
			for(int a=j; a<=N; a++){
				final = re(count, a);
//				printf("	%d\n", final);
				if(final > max) {
					max = final;
				}
				count = 1;
			}
			
		} else {
			for(int a=N; a<=j; a++){
				final = re(count, a);
//				printf("	%d\n", final);
				if(final > max) {
					max = final;
				}
				count = 1;
			}
		}
		printf("%d %d %d\n", N, j, max);
	}
	return 0;
}