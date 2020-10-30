#include<bits/stdc++.h>

int main(){
	
	int n;
	scanf("%d", &n);
	
	int num, arr[106];
	for(int i = 1; i <= n; i++){
		scanf("%d", &num);
		arr[num] = i;
	}
	printf("%d", arr[1]);
	for(int j = 2; j <= n; j++){
		printf(" %d", arr[j]);
	}
	printf("\n");
	
	return 0;
}