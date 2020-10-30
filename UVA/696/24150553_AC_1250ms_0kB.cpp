#include<stdio.h>

int main(){
	
	int M, N;
	
	while(1){
		scanf("%d %d", &M, &N);
		if(M == 0 && N == 0) break;
		
		int count = 0;
		
		if(M == 1 || N == 1){
			count = M*N;
			printf("%d knights may be placed on a %d row %d column board.\n", count, M, N);
		}
		else if(M == 2 || N == 2){
			int balik = 0;
			if(M != 2){
				int temp = M;
				M = N;
				N = temp;
				balik = 1;
			}
			
			int dua = 4; count = 0;
			for(int i = 0; i < N; i++){
				
				if(dua == 4){
					count += 2;
				}
				else if(dua == 5){
					count += 2;
					dua = 1;
				}
				dua++;
			}
			
			if(balik){
				int temp = M;
				M = N;
				N = temp;
			}
			printf("%d knights may be placed on a %d row %d column board.\n", count, M, N);
		}
		else {
			for(int x = 1; x <= M; x++){
				for(int y = 1; y <= N; y++){
					if(x % 2 == 1){
						if(y % 2 == 1){
							count++;
						}
					}
					else if(x % 2 == 0){
						if(y % 2 == 0){
							count++;
						}
					}
				}
			}
			printf("%d knights may be placed on a %d row %d column board.\n", count, M, N);
		}
		
		
	}
	
	
	return 0;
}

/*

2 3
5 5
4 7
0 0

*/