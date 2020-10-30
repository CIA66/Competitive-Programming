#include<stdio.h>
#include<math.h>


long long int GCD(long long int a, long long int b){
	if(b == 0) return a;
	return GCD(b, a%b);
}

long long int LCM(long long int a, long long int b){
	return (a * b) / GCD(a, b);
}


long long int arr[100000006];

long long int C(long long int N){
	
	long long int batas = (long long int)sqrt(N);
//	printf("%d\n", batas);
	
	long long int n = N;
	
	long long int idx = 0;
	for(long long int i=1; i<=batas; i++){
		
		if(n % i == 0){
			arr[idx] = i;
//			printf("%lld\n", arr[idx]);
			idx++;
			int temp = n / i;
			if(temp != i) {
				arr[idx] = temp;
//				printf("%lld\n", arr[idx]);
				idx++;
			}
		}
	}
	
	long long int count = 0;
	
	for(long long int k=0; k<idx; k++){
		for(long long int l=k; l<idx; l++){
			if(LCM(arr[k], arr[l]) == N){
				count++;
			}
		}
	}
	
	return count;
}

int main(){
	
	long long int N;
	
	while(1){
		scanf("%lld", &N);
		if(N == 0) break;
		printf("%lld %lld\n", N, C(N));
	}

	return 0;
}