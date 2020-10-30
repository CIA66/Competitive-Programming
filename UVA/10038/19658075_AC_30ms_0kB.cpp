#include<stdio.h>

int main(){
	int jolly[3006], diff[3006];
	int N = 0;
	while(scanf("%d", &N) != EOF){
		for(int a=0; a<N; a++){
			scanf("%d", &jolly[a]);
		}
		int i=0;
		for(int b=1; b<N; b++){
			diff[i] = jolly[b] - jolly[b-1];
			if(diff[i] < 0){
				diff[i] *= -1;
			}
			i++;
		}
//		for(int q=0; q<N-1; q++){
//			printf("%d ", diff[q]);
//		}
//		puts("");
		int temp = 0;
		for(int x=0; x<N; x++){
			for(int y=x; y<N-1; y++){
				if(diff[y] < diff[x]){
					temp = diff[y];
					diff[y] = diff[x];
					diff[x] = temp;
				}
			}
		}
//		for(int q=0; q<N-1; q++){
//			printf("%d ", diff[q]);
//		}
//		puts("");
		int truu = 1;
		int d = 1;
		for(int c=0; c<N-1; c++){
			if(diff[c] != d){
				truu = 0;
				break;
			}
			d++;
		}
		if(truu) printf("Jolly\n");
		else printf("Not jolly\n");
	}
	return 0;
}