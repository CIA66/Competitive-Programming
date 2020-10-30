#include<stdio.h>
#include<math.h>

int test(int N){
		
	int count = 0;
	int batas = (int)sqrt(N);
	for(int i=1; i<=batas; i++){
		
		if(N % i == 0){
			count++;
			int temp = N / i;
			if(N % temp == 0){
				if(temp != i){
					count++;
				}
			}
		}
	}
	return count;
}

//int arr[100000006];
//
//int init(){
//	for(int i=1; i<=1000; i++){
//		arr[i] = test(i);
////		printf("%d %d\n", i, arr[i]);
//	}
//}

int main(){
	
	
	int T;
	
	scanf("%d", &T);
	
	for(int a=0; a<T; a++){
		
		int L, U;
		
		scanf("%d %d", &L, &U);
		
		int max = 0, nilaiMax = 0;
		
		for(int i=L; i<=U; i++){
			int temp = test(i);
			if(temp > nilaiMax){
				max = i;
				nilaiMax = temp;
			}
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U, max, nilaiMax);
		
//		printf("%d %d\n", arr[L], arr[U]);
	}
	
	return 0;
}