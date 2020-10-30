#include<stdio.h>

char S[2000006];

int main(){
	int L = 0;
	while(1){
		scanf("%d", &L);
		getchar();
		if(L == 0) break;
		int minR = 2000000, minD = 2000000;
		int positionR = -1, positionD = -1, adaZ = 0;
		for(int a=0; a<L; a++){
			scanf("%c", &S[a]);
			if(S[a] == 'Z') adaZ = 1;
			else if(S[a] == 'R'){
				positionR = a;
				if(positionD > -1){
					if(minR > (positionR - positionD)) minR = (positionR - positionD);
				}
			} else if(S[a] == 'D'){
				positionD = a;
				if(positionR > -1){
					if(minD > (positionD - positionR)) minD = (positionD - positionR);
				}
			}
//			printf("position R:%d D:%d\n", positionR, positionD);
//			printf("min R:%d D:%d\n", minR, minD);
		}
		if(positionR == -1 || positionD == -1) printf("0\n");
		else if(adaZ) printf("0\n");
		else{
			if(minD < minR) printf("%d\n", minD);
			else printf("%d\n", minR);
		}
	}
	
	return 0;
}