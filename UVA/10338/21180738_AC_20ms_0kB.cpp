#include<stdio.h>
#include<string.h>

int main(){
	
	unsigned long long int N[26];
	
	for(int i=1; i<=20; i++){
		N[i] = 1;
		for(int j=i; j>1; j--){
			N[i] *= j;
		}
//		printf("%d : %llu\n", i, N[i]);
	}
	
	int T;
	
	scanf("%d", &T);
	
//	printf("Hello world\n");

	for(int a=1; a<=T; a++){
		char str[26];
		scanf("%s", str);
		int len = strlen(str);
		
		unsigned long long int hasil = N[len];
		
		for(int k=0; k<len; k++){
			
//			unsigned long long int temp = 0;
			int count = 0;
			for(int l=0; l<len; l++){
				if(str[k] == str[l]){
					if(l < k) break;
//					printf("%d %d - %c sama\n", k, l, str[k]);
					count++;
				}
			}
			if(count > 1){
//				printf("\ncount : %d\n", count);
//				printf("N : %llu\n", N[count]);
				hasil /= N[count];
//				printf("hasil : %llu\n", hasil);
			}
			
		}
		printf("Data set %d: %llu\n", a, hasil);
	}
	
	
	return 0;
}