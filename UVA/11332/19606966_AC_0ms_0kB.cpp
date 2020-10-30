#include<stdio.h>


int sum(int a){
	
	if(a < 10) return a;
	int toSum = a % 10;
	int total = toSum;
	int num = a / 10;
	
	while(num > 0){
		toSum = num % 10;
		total += toSum;
		num /= 10;
	}
	
	if(total > 9) return sum(total);
	return total;
}


int main(){
	int N = 0;
	while(1){
		scanf("%d", &N);
		if(N == 0) break;
		int total = 0;
		total = sum(N);
		printf("%d\n", total);
	}
	return 0;
}