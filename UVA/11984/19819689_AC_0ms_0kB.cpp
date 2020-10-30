#include<stdio.h>

int main(){
	int T = 0;
	scanf("%d", &T);
	double C, d, F, Celcius;
	for(int a=0; a<T; a++){
		scanf("%lf %lf", &C, &d);
		F = (C / 5 * 9) + d;
		Celcius = (F * 5 / 9);
		
		printf("Case %d: %.2lf\n", a+1, Celcius);
	}
}