#include<stdio.h>

int main(){
	int N = 0;
	scanf("%d", &N);
	for(int a=0; a<N; a++){
		int L = 0;
		scanf("%d", &L);
		int train[56] = {0};
		for(int b=0; b<L; b++){
			scanf("%d", &train[b]);
		}
		int count = 0;
		for(int c=0; c<L-1; c++){
			for(int d=0; d<L-c-1; d++){
				if(train[d] > train[d+1]){
					count++;
					int temp = train[d+1];
					train[d+1] = train[d];
					train[d] = temp;
				}
			}
		}
		printf("Optimal train swapping takes %d swaps.\n", count);
	}
	return 0;
}