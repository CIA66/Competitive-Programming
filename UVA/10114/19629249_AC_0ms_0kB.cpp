#include<stdio.h>

int main(){
	int duration = 0; double downPayment = 0, amountOfLoan = 0; int records = 0;
	int m = 0; double depre;
	double  initial = amountOfLoan + downPayment;
	while(1){
		scanf("%d %lf %lf %d", &duration, &downPayment, &amountOfLoan, &records);
		if(duration < 0) break;
		
		double thisMonthDepreciation[102];
		for(int a=0; a<records; a++){
			scanf("%d %lf", &m, &depre);
			for(int i=m; i<102; i++){
				thisMonthDepreciation[i] = depre;
			}
		}
		int month = 0;
		double depreciation, value, loan;
		depreciation = amountOfLoan / duration;
		value = (downPayment + amountOfLoan) * (1 - thisMonthDepreciation[0]);
		loan = amountOfLoan;
//		printf("%d %f %f %f\n", month, depreciation, value, loan);
		while(value < loan){
			month++;
			loan -= depreciation;
			value *= (1 - thisMonthDepreciation[month]);
//			printf("%d %f %f %f\n", month, depreciation, value, loan);
		}
		if(month == 1) printf("%d month\n", month);
		else printf("%d months\n", month);
		
	}
	return 0;
}