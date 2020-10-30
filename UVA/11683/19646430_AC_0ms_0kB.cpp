#include<stdio.h>
#include<string.h>

int X[10006];
int main(){
	int A = 0, C = 0;
	while(1){
		scanf("%d %d", &A, &C);
		if(A == 0 && C == 0) break;
		int count = 0;
		
		scanf("%d", &X[0]);
		count = A - X[0];
		
		for(int a=1; a<C; a++){
			scanf("%d", &X[a]);
			if(X[a] < X[a-1]){
				count += (X[a-1] - X[a]);
			}
		}
		printf("%d\n", count);
	}
	return 0;
}