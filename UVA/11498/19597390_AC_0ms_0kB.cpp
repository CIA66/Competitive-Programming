#include<stdio.h>

int main(){
	int K = 0, N = 0, M = 0;
	int X = 0, Y = 0;
	while(1){
		scanf("%d", &K);
		if(K == 0) break;
		scanf("%d %d", &N, &M);
		for(int a=0; a<K; a++){
			scanf("%d %d", &X, &Y);
			if(X == N || Y == M) printf("divisa\n");
			else if(X < N && Y > M) printf("NO\n");
			else if(X > N && Y > M) printf("NE\n");
			else if(X > N && Y < M) printf("SE\n");
			else if(X < N && Y < M) printf("SO\n");
		}
	}
	
	return 0;
}