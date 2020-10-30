#include<stdio.h>

int main(){
	int T = 0;
	int urutan[1006];
	char angka[1006][1006];
	int enter = 0;
	int num, N = 0;
	scanf("%d", &T);
	for(int a=0; a<T; a++){
		if(enter == 1){
			printf("\n");
		}	
		num = 0;
		N = 0;
		while(true){
			scanf("%d", &num);
			urutan[N] = num;
			N++;
			if(getchar() == '\n'){
				break;
			}
		}
		
		for(int b=0; b<N; b++){
			scanf("%s", &angka[urutan[b]-1]);
		}
		for(int c=0; c<N; c++){
			printf("%s\n", angka[c]);
		}
		enter = 1;
	}
	return 0;
}