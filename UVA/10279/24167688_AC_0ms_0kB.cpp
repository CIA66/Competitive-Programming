#include<stdio.h>

int main(){
	int game, n, start = 1, hasil[16][16], tc = 1;
	char mine[16][16], touch[16][16];
	
	int dirJ[] = {-1, -1, -1, +0, +0, +1, +1, +1};
	int dirI[] = {+1, +0, -1, +1, -1, +1, -1, +0};
	
	scanf("%d", &game);
	getchar();
	
	while(game--){
		if(start == 1){
			start = 0;
		}
		else if(start == 0){
			getchar();
		}
		scanf("%d", &n);
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				hasil[i][j] = 0;
			}
		}
		
		for(int i = 0; i < n; i++){
			scanf("%s", mine[i]);
			for(int j = 0; j < n; j++){
				if(mine[i][j] == '*'){
					
//					printf("* ada di %d %d\n", i, j);
					hasil[i][j] = -1;
					for(int k = 0; k < 9; k++){
						int xx = j + dirJ[k];
						int yy = i + dirI[k];
						if(xx >= 0 && xx < n && yy >= 0 && yy < n && hasil[yy][xx] != -1){
//							printf("%d %d\n", xx, yy);
							hasil[yy][xx]++;
						}
					}
				}
				
			}
		}
		
		if(tc != 1){
			printf("\n");
		}
		
		int kalah = 0;
		for(int i = 0; i < n; i++){
			scanf("%s", touch[i]);
			if(kalah) continue;
			for(int j = 0; j < n; j++){
				if(touch[i][j] == 'x'){
					if(hasil[i][j] == -1){
						kalah = 1;
					}
				}
			}
		}
		
		if(kalah){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(touch[i][j] == 'x'){
						if(hasil[i][j] == -1) printf("*");
						else printf("%d", hasil[i][j]);	
					}
					else if(hasil[i][j] == -1) printf("*");
					else printf(".");
				}
				printf("\n");
			}
		
		}
		else{
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(touch[i][j] == 'x') printf("%d", hasil[i][j]);
					else printf(".");
				}
				printf("\n");
			}
		}
		
		tc++;
		
	}
	
	
	return 0;
}

/*

1
8
...**..*
......*.
....*...
........
........
.....*..
...**.*.
.....*..
xxx.....
xxxx....
xxxx....
xxxxx...
xxxxx...
xxxxx...
xxx.....
xxxxx...


001.....
0013....
0001....
00011...
00001...
00123...
001.....
00123...

*/