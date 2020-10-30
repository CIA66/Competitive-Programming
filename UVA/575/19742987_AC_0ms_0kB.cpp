#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
	char N[3000];
	
	while(1){
		scanf("%s", N);
		if(strcmp(N, "0") == 0){
			break;
		}
		
		int len = strlen(N);
		long long int sum = 0;
		int i = 0;
		
		while(len > 0){
			sum += (N[i] - '0') * (pow(2,len) - 1);
			i++;
			len--;
		}
		printf("%lld\n", sum);
		
	}
	return 0;
}