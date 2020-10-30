#include<stdio.h>

int main(){
	int N = 0, tc = 1;
	while(1){
		scanf("%d", &N);
		if(N < 0) break;
		int count = 0, before = 0, sum = 1;
		if(N == 1){
			count = 0;
		}
		else {
			while(1){
				if(sum > N){
					break;
				}
				if(sum == N){
					break;
				}
				before = sum;
				sum += before;
				count++;
			}
		}
		
		printf("Case %d: %d\n", tc++, count);
	}
	return 0;
}