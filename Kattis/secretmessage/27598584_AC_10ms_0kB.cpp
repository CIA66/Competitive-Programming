#include<bits/stdc++.h>

using namespace std;

int nextPerfectSquare(int len){ 

    int nextN = floor(sqrt(len)) + 1; 
  
    return nextN * nextN; 
} 

	
int main(){
	
	int N;
	scanf("%d", &N); getchar();
	
	
	while(N--){
		char str[10009];
		scanf("%s", str); getchar();
		int len = strlen(str), K, M;
		if(sqrt(len)*sqrt(len) == len){
			M = len;
			K = sqrt(M);
		}
		else{
			M = nextPerfectSquare(len);
			K = sqrt(M);
		}
		
//		printf("K : %d\n", K);
		char jadi[106][106];
		int idx = 0;
		for(int i = 0; i < K; i++){
			for(int j = 0; j < K; j++){
				if(idx == len) jadi[i][j] = '*';
				else jadi[i][j] = str[idx++];
			}
		}
//		for(int i = 0; i < K; i++){
//			for(int j = 0; j < K; j++){
//				printf("%c", jadi[i][j]);
//			}
//			printf("\n");
//		}
		for(int i = 0; i < K; i++){
			for(int j = K-1; j >= 0; j--){
				if(jadi[j][i] != '*') printf("%c", jadi[j][i]);
			}
		}
		printf("\n");
	}
//	getchar();
	return 0;
}