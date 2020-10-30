#include<stdio.h>
#include<string.h>

int main(){
	int N = 0;
	
	scanf("%d", &N);
	for(int a=0; a<N; a++){
		int M = 0;
		scanf("%d", &M);
		
		int X1 = M, X2 = M;
		int b1 = 0;
		
		while(X1 > 0){
			b1 += X1 % 2;
			X1 /= 2; 
		}

		int b2 = 0;
		int temp = 0;
		while(X2 > 0){
			temp = X2 % 10;
			if(temp == 1 || temp == 2 || temp == 4 || temp == 8){
				b2++;
			} else if(temp == 3 || temp == 5 || temp == 6 || temp == 9){
				b2 += 2;
			} else if(temp == 7){
				b2 += 3;
			}
			X2 /= 10;
		}
		
		printf("%d %d\n", b1, b2);
	}
	return 0;
}