#include<bits/stdc++.h>

int arr[5005];

int main(){
	
	int n;
	scanf("%d", &n);
	
	int a = 1, b = 2, one, two, three;
	int sum;
	
	for(int i = 1; i <= n; i++){
		
		if(i == 1) {
			printf("? %d %d\n", i, i+1); fflush(stdout);
			scanf("%d", &sum);
			one = sum;
		}
		else if(i == 2){
			printf("? %d %d\n", i, i+1); fflush(stdout);
			scanf("%d", &sum);
			two = sum;
		}
		else if(i == 3){
			printf("? %d %d\n", 1, i); fflush(stdout);
			scanf("%d", &sum);
//			printf("one + two :%d\n", one + two);
			three = ((one + two) - sum) / 2;
//			printf("three : %d\n", three);
			arr[2] = three;
			arr[1] = one - three;
			arr[3] = sum - arr[1];
		} 
		else {
			printf("? %d %d\n", i-1, i); fflush(stdout);
			scanf("%d", &sum);
			arr[i] = sum - arr[i-1];
		}
	}
	
	printf("!");
	for(int i = 1; i <= n; i++){
		printf(" %d", arr[i]);
	}
	printf("\n"); fflush(stdout);
	
	return 0;
}