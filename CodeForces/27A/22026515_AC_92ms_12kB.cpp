#include<bits/stdc++.h>

int main(){
	
	int n;
	scanf("%d", &n);
	
	int arr[3006], num;
	
	for(int i = 1; i <= 3001; i++){
		arr[i] = 0;
	}
	
	for(int i = 0; i < n; i++){
		scanf("%d", &num);
		arr[num] = 1;
	}
	
	for(int j = 1; j <= 3001; j++){
		if(arr[j] == 0){
			printf("%d\n", j);
			break;
		}
	}
	
	return 0;
}