#include<stdio.h>

int main(){
	
	int N = 0;
	while(1){
		scanf("%d", &N);
		if(N == 0) break;
		int bet = 0, max = 0, temp = 0;
		for(int a=0; a<N; a++){
			scanf("%d", &bet);
			temp += bet;
			if(temp > max){
				max = temp;
			}
			if(temp < 0){
				temp = 0;
			}
		}
		if(max > 0) printf("The maximum winning streak is %d.\n", max);
		else printf("Losing streak.\n");
	}
	
	return 0;
}