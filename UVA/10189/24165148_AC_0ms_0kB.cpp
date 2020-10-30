#include<stdio.h>

int main(){
	
	int n, m;
	char mine[106][106];
	int hasil[106][106];
	
	int dirJ[] = {-1, -1, -1, +0, +0, +1, +1, +1};
	int dirI[] = {+1, +0, -1, +1, -1, +1, -1, +0};
	
	int tc = 1;
	while(1){
		scanf("%d %d", &n, &m); getchar();
		if(n == 0 && m == 0) break;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				hasil[i][j] = 0;
			}
		}
		
		for(int i = 0; i < n; i++){
			scanf("%s", mine[i]);
			for(int j = 0; j < m; j++){
				if(mine[i][j] == '*'){
					
//					printf("* ada di %d %d\n", i, j);
					hasil[i][j] = -1;
					for(int k = 0; k < 9; k++){
						int xx = j + dirJ[k];
						int yy = i + dirI[k];
						if(xx >= 0 && xx < m && yy >= 0 && yy < n && hasil[yy][xx] != -1){
//							printf("%d %d\n", xx, yy);
							hasil[yy][xx]++;
						}
					}
				}
				
			}
		}
		
		if(tc != 1) printf("\n");
		printf("Field #%d:\n", tc++);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(hasil[i][j] == -1) printf("*");
				else printf("%d", hasil[i][j]);
			}
			printf("\n");
		}
	}
	
	return 0;
}

/*

4 4
*...
....
.*..
....
3 5
**...
.....
.*...
0 0


*/