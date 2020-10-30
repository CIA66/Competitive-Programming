#include<bits/stdc++.h>

void bSort(int N, int arr[]){
	
	for(int i = 1; i <= N; i++){
		for(int j = N; j > 1; j--){
			if(arr[j] < arr[j-1]){
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
}

int main(){
	
	int tc = 1;
	while(1){
		int N, Q;
		scanf("%d %d", &N, &Q);
		
		if(N == 0 && Q == 0) break;
		
		int mar[10006] = {0};
		
		for(int i = 1; i <= N; i++){
			scanf("%d", &mar[i]);
		}
		
		bSort(N, mar);
		
//		for(int i = 1; i <= N; i++){
//			printf("%d ", mar[i]);
//		}
		
		printf("CASE# %d:\n", tc++);
		for(int i = 1; i <= Q; i++){
			int temp;
			scanf("%d", &temp);
			int found = 0;
			for(int j = 1; j <= N; j++){
				if(temp == mar[j]){
					printf("%d found at %d\n", temp, j);
					found = 1;
					break;
				}
			}
			if(!found) printf("%d not found\n", temp);
		}
	}
	return 0;
}