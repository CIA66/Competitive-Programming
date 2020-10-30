#include<stdio.h>
#include<math.h>

int main(){
	double n, p;
	
	while(scanf("%lf", &n) != EOF){
		scanf("%lf", &p);
		printf("%.lf\n", pow(p, (1.0 / n)));
	}
	
	return 0;
}