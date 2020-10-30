#include<stdio.h>



struct Data{
	char name[26];
	int low;
	int hi;
}data[10006];


int main(){
	
	int T = 0;
	scanf("%d", &T);
	for(int a=0; a<T; a++){
		int D = 0;
		scanf("%d", &D); 
		
		for(int b = 0; b<D; b++){
			scanf("%s %d %d", data[b].name, &data[b].low, &data[b].hi); 
		}
		
		int Q = 0, count = 0, idx = 0;
		scanf("%d", &Q);
		for(int c=0; c<Q; c++){
			int P = 0;
			scanf("%d", &P);
			count = 0;
			for(int d=0; d<D; d++){
				if(data[d].low <= P && P <= data[d].hi){
					count++;
					idx = d;
				}
				if(count > 1){
					break;
				}
			}
			if(count == 1) printf("%s\n", data[idx].name);
			else printf("UNDETERMINED\n");
		}
		if(a != T-1) puts("");
	}
	return 0;
}