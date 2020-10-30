#include<stdio.h>

int main(){
	int k = 0;
	int pertama = 1;
	while(1){
		
		scanf("%d", &k);
		int list[14];
		if(k == 0) break;
		
		if(pertama == 1){
			pertama = 0;
		} else if(pertama == 0){
			puts("");
		}
		
		for(int i=0; i<k; i++){
			scanf("%d", &list[i]);
		}
		for(int a=0; a<k; a++){
			for(int b=a+1; b<k; b++){
				for(int c=b+1; c<k; c++){
					for(int d=c+1; d<k; d++){
						for(int e=d+1; e<k; e++){
							for(int f=e+1; f<k; f++){
								printf("%d %d %d %d %d %d\n", list[a], list[b], list[c], list[d], list[e], list[f]);
							}
						}
					}
				}
			}
		}
	}
	return 0;
}