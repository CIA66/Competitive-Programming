#include<stdio.h>
#include<string.h>

int main(){
	int C = 0, N = 0;
	scanf("%d", &C);
	for(int a = 0; a < C; a++){
		scanf("%d", &N);
		int sum = 0;
		double student[1006] = {0};
		for(int b=0; b<N; b++){
			scanf("%lf", &student[b]);
			sum += student[b];
		}
		double average = (double)sum / N;
		int above = 0;
		for(int c=0; c<N; c++){
			if(student[c] > average){
				above++;
			}
		}
		double final = (double)above / N * 100;
		printf("%.3lf%%\n", final);
	}
	
	return 0;
}