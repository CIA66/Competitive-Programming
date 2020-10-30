#include<bits/stdc++.h>

#define MAXN 524288

int arr[MAXN+6];
int lock[MAXN+ 6];

int main(){
//	printf("%d\n", (3 & 7) == 3);
	int N, M;
	scanf("%d %d", &N ,&M);
	
	int total = 1 << N;
	int loop = total;
//	printf("%d\n", total);
	
	int a, b;
	for(int i = 0; i < M; i++){
		scanf("%d %d", &a, &b);
		
		int temp = (1 << a-1) | (1 << b-1);
//		printf("%d\n", temp);
		
		for(int j = 0; j < loop; j++){
//			printf("j : %d lock : %d  bool : %d\n", j, lock[j], ((temp & j) == temp));
			if((lock[j] == 0) && ((temp & j) == temp)){
//				printf("j : %d\n", j);
				total--;
				lock[j] = 1;
			}
		}
	}
	printf("%d\n", total);
	return 0;
}