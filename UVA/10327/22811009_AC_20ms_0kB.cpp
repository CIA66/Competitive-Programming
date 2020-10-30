#include<bits/stdc++.h>

int main(){
	
	int L;
	while(scanf("%d", &L) != EOF){
		int train[1006];
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
		
//		for(int i = 0; i < L; i++){
//			printf("%d ", train[i]);
//		}
		printf("Minimum exchange operations : %d\n", count);
	}
	
	return 0;
}