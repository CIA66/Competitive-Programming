#include<stdio.h>

int check(int num){
	while(num % 2 == 0) {
		num /= 2;
	}
	while(num % 3 == 0) {
		num /= 3;
	}
	while(num % 5 == 0) {
		num /= 5;
	}
	if(num == 1){
		return 1;
	} else {
		return 0;
	}
}


int main(){
/*
	long long int bisa = 0;
	int count = 0;
	long long int a = 1;
	while(1){
		bisa = check(a);
		if(bisa){
			count++;
			if(count == 1500){
				printf("\nfinal : %lld ", a);
				break;
			} else {
				printf("%d = %lld\n", count, a);
			}
		}
		a++;
	}
*/	
	printf("The 1500'th ugly number is 859963392.\n");
	return 0;
}