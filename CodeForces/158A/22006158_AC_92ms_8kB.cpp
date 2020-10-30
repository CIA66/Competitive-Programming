#include<bits/stdc++.h>


using namespace std;

int main(){
	
	
	int n, k;
	scanf("%d %d", &n, &k);
	
	int arr[100];
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	
	int count = 0;
	for(int j = 0; j < n; j++){
		if(arr[j] > 0 && arr[j] >= arr[k-1]){
			count++;
		}
		if(arr[j] < arr[k-1]) break;
	}
	printf("%d\n", count);
	
	return 0;
}