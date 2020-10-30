#include<stdio.h>

int main(){
//	long long int sum = 1;
//	for(int a=0; a<32; a++){
//		sum *= 2;
//	}
//	printf("%llu\n", sum);
	long long int one = 0, two = 0;
	
	while(scanf("%lld", &one) != EOF){
		scanf("%lld", &two);
		if(two > one){
			printf("%lld\n", (two - one));
		}
		else {
			printf("%lld\n", (one - two));
		}
	}
	return 0;
}