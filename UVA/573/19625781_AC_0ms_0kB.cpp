#include<stdio.h>
// aaaa ngselin gbangetttttt 
// HUGE DIFFERENCE
// double has 2x the precidion of float. In general a double has 15 digits of precision, while float has 7
int main(){
	double H = 0.0, U = 0.0, D = 0.0, F = 0.0;
	while(1){
		scanf("%lf %lf %lf %lf", &H, &U, &D, &F);
		if(H == 0) break;
		
		double fatigue = U * F / 100;
		int day = 1;
		double afterClimb = 0.0;
		
		while(1){
			// U nya gk mungkin (-)
			if(U > 0) afterClimb = afterClimb + U;
			U -= fatigue;
			
			if(afterClimb > H){
				break;	
			}
			afterClimb = afterClimb - D;
			if(afterClimb < 0){
				break;
			}
			
			day++;
		}
		if(afterClimb >= 0) printf("success on day %d\n", day);
		else printf("failure on day %d\n", day);
	}
	return 0;
}