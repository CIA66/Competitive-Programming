#include<stdio.h>

int main(){
	int N = 0;
	
	while(scanf("%d", &N) != EOF){
		int f = 0;
		for(int a=0; a<N; a++){
			scanf("%d", &f);
			double premium  = 0;
			double total = 0;
			for(int b=0; b<f; b++){
				premium = 0;
				double size = 0, animal = 0, environtment = 0;
				scanf("%lf %lf %lf", &size, &animal, &environtment);
				if(size == 0 || animal == 0 || environtment == 0) premium = 0;
				else {
					premium = (size / animal * environtment * animal);
					
				}
//				printf("%d\n", premium);
				total += premium;
			}
			printf("%.lf\n", total);

		}
		
	}
	return 0;
}
