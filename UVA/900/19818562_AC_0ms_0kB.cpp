#include<stdio.h>



int main(){
	long long int N = 0;
	long long int wall[56];
	while(1){
		scanf("%lld", &N);
		if(N == 0) break;
		wall[0] = 0;
		wall[1] = 1;
		for(int a=2; a<=N+1; a++){
			wall[a] = wall[a-1] + wall[a-2];
		}
		printf("%lld\n", wall[N+1]);
	}
	return 0;
}