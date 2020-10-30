#include<stdio.h>

int isPrime(int x){
	
	if(x <= 1) return 0;
	for(int i=2; i<x; i++){
		if(x % i == 0) return 0;
	}
	return 1;
}

void start(int arr[]){
	
	for(int i=0; i<=10000; i++){
		arr[i] = isPrime(i);
	}
}

int main(){
	
	
	int T;
	int L, H;
	
	scanf("%d", &T);
	
	int prime[10000];
	start(prime);
	
	for(int a=0; a<T; a++){
		
		scanf("%d %d", &L, &H);
		
		int valid = 0;
		int first = 1;
		for(int i=L; i<=H; i++){
			
			int temp = 0;
			for(int k=1; k<=i; k++){
				if(i % k == 0){
					temp++;
				}
			}
			
//			printf("i : %d - temp : %d\n", i, temp);
			if(prime[temp] == 1){
				valid = 1;
				
				if(first){
					first = 0;
					printf("%d", i);
				}
				else{
					printf(" %d", i);
				}
			}
		}
		
		if(valid == 0) printf("-1\n");
		else puts("");
	}
	return 0;
}