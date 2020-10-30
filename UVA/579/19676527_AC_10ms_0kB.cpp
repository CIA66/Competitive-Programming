#include<stdio.h>

int main(){
	double H = 0, M = 0;
	while(1){
		scanf("%lf:%lf", &H, &M);
		if(H == 0 && M == 0) break;
		H = (H * 30) + M * 0.5;
		M = M * 6.0;
//		printf("%lf %lf\n", H, M);
		double total = H - M;
		if(total < 0) total *= -1;
		if(total > 180) total = 360 - total;
		printf("%.3lf\n", total);
	}
	return 0;
}