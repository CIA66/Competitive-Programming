#include<stdio.h>

int orang[1000006];

int main(){
	
	int T;
	scanf("%d", &T);
//	printf("%d\n", T);
	
	while(T--){
		int papan[106];
		for(int i = 0; i < 101; i++){
			papan[i] = -1;
		}
		
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		
		for(int i = 0; i <= a; i++){
			orang[i] = 0;
		}
		while(b--){
			int s, e;
			scanf("%d %d", &s, &e);
			papan[s] = e;
		}
		
		int dice, curr = 1, done = 0;
		while(c--){
			scanf("%d", &dice);
			if(!done){
				if(orang[curr] == 0){
					orang[curr] = 1;
				}
				
				orang[curr] += dice;
				
				if(papan[orang[curr]] != -1){
					orang[curr] = papan[orang[curr]];
				}
				
				if(orang[curr] >= 100){
					orang[curr] = 100;
					done = 1;
				}
				
				curr++;
				if(curr > a){
					curr = 1;
				}
			}
		}
		
		for(int k = 1; k <= a; k++){
			if(orang[k] == 0) printf("Position of player %d is 1.\n", k);
			else printf("Position of player %d is %d.\n", k, orang[k]);
		}
	}
	return 0;
}

/*

1
3 1 3
4 20
3
4
5

*/