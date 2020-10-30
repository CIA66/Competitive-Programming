#include<bits/stdc++.h>

int main(){
	
	int n;
	scanf("%d", &n);
	
	int num, count = 1, before;
	scanf("%d", &before);
	
	for(int i = 1; i < n; i++){
		scanf("%d", &num);
		if(num != before) {
			count++;
			before = num;
		}
		
	}
	printf("%d\n", count);
	
	return 0;
}