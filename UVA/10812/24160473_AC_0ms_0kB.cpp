#include<stdio.h>

#define ll long long

int main(){
	
	int N;
	scanf("%d", &N);
	unsigned int s, d, sel, num1, num2;
	
	while(N--){
		scanf("%u %u", &s, &d);
		if(d > s){
			printf("impossible\n");
			continue;
		}
		int impo = 1;
		for(num2 = s; num2 >= 0; num2--){
			num1 = s - num2;
//			printf("num2 : %d  num1 : %d\n", num2, num1);
			if((num2 - num1) == d){
				printf("%u %u\n", num2, num1);
				impo = 0;
				break;	
			}
			if(num2 == -1) break;
		}
		if(impo) printf("impossible\n");
	}
	
	return 0;
}