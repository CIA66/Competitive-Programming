#include<stdio.h>
#include<math.h>

long long H(int n){
	
	if(n < 1) return 0;
	long long int res = 0;
	
	int batas = (int)sqrt(n);
	
	if(batas * batas == n){
		res = res + (n / batas);
		batas--;
	}
	
	for( int i = 1; i <= batas; i=i+1 ){
		
//		if(i == (int)sqrt(n)){
//			printf("-----\n");
//		}

//		printf("i. %d\n", i);
		res = res + (n/i);
		
//		printf("%d/%d= %d  res : %d\n", n, i, n / i, res);
		res += n/i - batas;
//		printf("%d. %d %d\n", i, batas, n/i - batas);
		
	}
	
	return res;
}

int main(){
	
	int T;
	
	scanf("%d", &T);
	
	for(int a=0; a<T; a++){
		
		int N;
		scanf("%d", &N);
		printf("%lld\n", H(N));
//		printf("\n\n");
	}	
	return 0;
}