#include<stdio.h>

int main(){
	int T = 0;
	scanf("%d", &T);
	int W = 0;
	int y1[1000] = {0}, y2[1000] = {0};
	for(int a=0; a<T; a++){
		getchar();
		scanf("%d", &W);
	
		int beda = 0;
		for(int b=0; b<W; b++){
			scanf("%d %d", &y1[b], &y2[b]);
		}
		
		beda = y2[0] - y1[0];
		int tru = 1;
		for(int c = 0; c < W ; c++){
			if((y2[c] - y1[c]) != beda){
				tru = 0;
				break;
			}
		}
		if(!tru) printf("no\n");
		else printf("yes\n");
		if(a != (T-1)) printf("\n");
	}
	return 0;
}