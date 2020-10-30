// H - Chess

#include<stdio.h>
#include<math.h>

int main(){
	
	int N;
	
	while(scanf("%d", &N)){
		int x = 0, y = 0;
		if(N == 0) break;
//		printf("%d	%d\n", N, (int)ceil(sqrt(N)));

		int row = (int)ceil(sqrt(N));
//		printf("%d\n", row);
		int diagonal = row * row - row + 1;
//		printf("	%d\n", diagonal);
		int temp = 0;
		if(N == diagonal){
			x = row;
			y = row;
		} else if(row % 2 == 0){
			if(N < diagonal){
//				printf("if 1\n");
				y = row;
				temp = diagonal - N;
				x = row - temp;
			} else {
//				printf("if 2\n");
				x = row;
				temp = N - diagonal;
				y = row - temp;
			}
		} else if(row % 2 == 1){
			if(N > diagonal){
//				printf("if 3\n");
				y = row;
				temp = N - diagonal;
				x = row - temp;
			} else {
//				printf("if 4\n");
				x = row;
				temp = diagonal - N;
				y = row - temp;
			}
		}
		
		printf("%d %d\n", x, y);
		
	}
	
	return 0;
}