#include<bits/stdc++.h>

void bsort(int n, int arr[]){
	for(int i = 0; i < n; i++){
		for(int j = n-1; j > i; j--){
			if(arr[j] < arr[j-1]){
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
}

int main(){
	
	int n, d, r;
	
	while(1){
		scanf("%d %d %d", &n, &d, &r);
		if(n == 0 && d == 0 && r == 0) break;
		
		int pagi[106], sore[106];
		for(int i = 0; i < n; i++){
			scanf("%d", &pagi[i]);
		}
		for(int i = 0; i < n; i++){
			scanf("%d", &sore[i]);
		}
		
		bsort(n, pagi);
		bsort(n, sore);
		
//		for(int i = 0; i < n; i++){
//			printf("%d ", pagi[i]);
//		}
//		puts("");
//		for(int i = 0; i < n; i++){
//			printf("%d ", sore[i]);
//		}
//		puts("");
		
		int sum = 0;
		for(int i = 0, j = n-1; i < n; i++, j--){
			int temp = pagi[i] + sore[j];
			if(temp > d){
				sum += ((temp - d) * r);
			}
		}
		
		printf("%d\n", sum);
	}
	
	return 0;
}