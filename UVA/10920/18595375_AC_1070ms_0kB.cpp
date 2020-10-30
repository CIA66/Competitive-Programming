#include<stdio.h>

int main(){
	long long int SZ, P;
	do{
		long long int flag, done = 0;
		scanf("%lld %lld", &SZ, &P);
		long long int a = SZ;
		long long int minus = 0;
		
		while(a>0){
			if(a == 1){
				printf("Line = %lld, column = %lld.\n", minus+1, minus+1);
				break;
			}
			long long int x = a-2;
			if(P <= a*a && P > x*x){
				flag = a*a;
				for(long long int b=a; b>0; b--){
					if(P == flag){
						printf("Line = %lld, column = %lld.\n", b+minus, a+minus);
						done = 1;
						break;
					}
					flag--;
				}
				if(done == 1) break;
				for(long long int c=a-1; c>0; c--){
					if(P == flag){
						printf("Line = %lld, column = %lld.\n", minus+1, minus+c);
						done = 1;
						break;
					}
					flag--;
				}
				if(done == 1) break;
				
				for(long long int d=2; d<=a; d++){
					if(P == flag){
						printf("Line = %lld, column = %lld.\n", minus+d, minus+1);
						done = 1;
						break;
					}
					flag--;
				}
				if(done == 1) break;
				
				for(long long int e=2; e<=a; e++){
					if(P == flag){
						printf("Line = %lld, column = %lld.\n", minus+a, minus+e);
						done = 1;
						break;
					}	
					flag--;
				}
				if(done == 1) break;
			}
			minus++;
			a = a-2;
		}
		
	}while(SZ != 0 && P != 0);
	
	return 0;
}