#include<stdio.h>

#define inf 100000000

int Stop(long long int n){
	
	int i = 0;
	
	while(n > 1){
		
//		printf("%d", i++);
		if(i > inf) return 0;
		
		if(n % 2 == 0){
			n = n / 2;
		}
		else{
			n = 3 * n + 3;
		}
		
		i++;
	}
	
	return 1;
}

int main(){
	
	long long int N;
	
	scanf("%lld", &N);
	
	if(Stop(N)){
		printf("TAK\n");
	}
	else{
		printf("NIE\n");
	}
	
	return 0;
}