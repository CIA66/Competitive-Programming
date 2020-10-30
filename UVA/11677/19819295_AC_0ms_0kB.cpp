#include<stdio.h>

int main(){
	int h1 = 0, m1 = 0, h2 = 0, m2 = 0;
	
	while(1){
		scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
		if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0) break;
		int sum1 = (h1 * 60) + m1;
		int sum2 = (h2 * 60) + m2;
		
		if(sum1 > sum2){
			sum2 += 1440;
		}
		printf("%d\n", sum2 - sum1);
	}
	return 0;
}