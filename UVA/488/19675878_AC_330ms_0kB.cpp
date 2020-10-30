#include<stdio.h>

int main(){
	int T = 0, A = 0, F = 0;
	scanf("%d", &T);
	for(int a=0; a<T; a++){
		scanf("%d %d", &A, &F);
		for(int b=0; b<F; b++){
			
			int num = 1;
			for(int i=1; i<=A; i++){
				for(int j=0; j<i; j++){
					printf("%d", num);
				}
				printf("\n");
				num++;
			}
			num--;
			num--;
			for(int k=A-1; k>=1; k--){
				for(int l=k; l>0; l--){
					printf("%d", num);
				}
				printf("\n");
				num--;
			}
			if(a != T-1 || b != F-1)printf("\n");
		}
	}
	return 0;
}