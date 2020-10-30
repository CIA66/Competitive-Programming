#include<stdio.h>

int main(){
	
	
	int N;
	int height[100006];
	
	scanf("%d", &N);
	
	height[0] = 0;
	for(int i=1; i<=N; i++){
		scanf("%d", &height[i]);
	}
	
	int energy = 0, dollar = 0;
	
	for(int k=0; k<N; k++){
		
		energy += (height[k] - height[k+1]);
		
		if(energy < 0){
			dollar += (energy * -1);
			energy = 0;
		}
		
//		printf("Height : %d -- Energy : %d -- Dolar : %d\n", height[k], energy, dollar);
	}
	
	printf("%d\n", dollar);
	
	return 0;
}