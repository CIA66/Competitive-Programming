#include<stdio.h>
#include<stdlib.h>

void sort(int arr[], int N){
	
	for(int i=0; i<N; i++){
		for(int j=N-1; j>i; j--){
			if(arr[j] > arr[j-1]){
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
}

int main(){
	
	int n, m;
	
	scanf("%d", &n);
	scanf("%d", &m);
	
	int arr[1006];
	
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	sort(arr, n);
	
	int count = 0;
	
	for(int j=0; j<n; j++){
		m -= arr[j];
		count++;
		if(m <= 0) break;
	}
	
	printf("%d\n", count);
	
	return 0;
}