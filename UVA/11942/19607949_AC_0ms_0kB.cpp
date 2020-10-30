#include<stdio.h>

int main(){
	int N = 0;
	scanf("%d", &N);
	printf("Lumberjacks:\n");
	for(int a=0; a<N ; a++){
		int lumberjack[12] = {0};
		int naik = 0, turun = 0, valid = 1;
		for(int b=0; b<10; b++){
			scanf("%d", &lumberjack[b]);
			if(b != 0){
				if(valid){
					if(lumberjack[b] < lumberjack[b-1]){
						turun++;
						if(naik != 0) valid = 0;
					} else if(lumberjack[b] > lumberjack[b-1]){
						naik++;
						if(turun != 0) valid = 0;
					}
				}	
			}
		}
		if(valid) printf("Ordered\n");
		else printf("Unordered\n");
	}
	return 0;
}