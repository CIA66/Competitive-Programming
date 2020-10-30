#include<stdio.h>

int main(){
	
	int T, N, wall;
	
	scanf("%d", &T);
	
	for(int i=1; i<=T; i++){
		
		scanf("%d", &N);
		
		int high = 0, low = 0, temp = 0;
		
		for(int a=0; a<N; a++){
			
			scanf("%d", &wall);
			
			if(a == 0){
				temp = wall;
			}
			else if(wall > temp){
				high++;
				temp = wall;
			}
			else if(wall < temp){
				low++;
				temp = wall;
			}
			
//			printf("Temp : %d\nHi : %d\nLow : %d\n", wall, high, low);
		}
		
		printf("Case %d: %d %d\n", i, high, low);	
	}

	return 0;
}