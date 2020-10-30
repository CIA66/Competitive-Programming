#include<stdio.h>

int main(){
	int T = 0;
	int N = 0;
	int time = 0;
	int sumMile = 0, sumJuice = 0;
	scanf("%d", &T);
	for(int a=1; a<=T; a++){
		scanf("%d", &N);
		sumMile = 0, sumJuice = 0;
		for(int b=0; b<N; b++){
			scanf("%d", &time);
			if(time >= 29) sumMile += (time / 30) * 10 + 10;
			else sumMile += 10;
			if(time >=59) sumJuice += (time / 60) * 15 + 15;
			else sumJuice += 15;
			
//			printf("%d %d\n", sumMile, sumJuice);
		}
		printf("Case %d: ", a);
		if(sumMile < sumJuice) printf("Mile %d\n", sumMile);
		else if(sumMile > sumJuice) printf("Juice %d\n", sumJuice);
		else printf("Mile Juice %d\n", sumMile);
	}
	return 0;
}