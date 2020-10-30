#include<bits/stdc++.h>

int main(){
	
	int T;
	scanf("%d", &T);
	
	for(int i = 0; i < T; i++){
		
		int L;
		scanf("%d", &L);
		
		int train[56];
		for(int j = 0; j < L; j++){
			scanf("%d", &train[j]);
		}
		
		int count = 0;
		for(int a = 0; a < L; a++){
			for(int b = L-1; b > a; b--){
				if(train[b] < train[b-1]){
					int temp = train[b];
					train[b] = train[b-1];
					train[b-1] = temp;
					count++;
				}
			}
		}
		
//		for(int j = 0; j < L; j++){
//			printf("%d ", train[j]);
//		}

		printf("Optimal train swapping takes %d swaps.\n", count);
	}
	return 0;
}