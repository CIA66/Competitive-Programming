#include<bits/stdc++.h>

using namespace std;

char chess[12][12];

int dirX[] = {+1, -1, +0, +0, +1, -1, +1, -1};
int dirY[] = {+0, +0, +1, -1, +1, +1, -1, -1};

int check(int i, int j){
	
	int xx = 0, yy = 0;
	for(int k = 1; k <= 8; k++){
		
		for(int m = 0; m < 8; m++){
			xx = i + (dirX[m] * k);
			yy = j + (dirY[m] * k);
			if(xx >= 0 && xx < 8 && yy >= 0 && yy < 8){
//				printf("%d %d\n", xx, yy);
				if(chess[xx][yy] == '*'){
//					printf("-- %d %d\n", xx, yy);
					return 0;
				}
			}
		}
	}
	return 1;
}	
	
int main(){
	
	for(int i = 0; i <= 9; i++){
		strcpy(chess[i], "");
	}

	for(int i = 0; i < 8; i++){
		scanf("%s", chess[i]);
	}
	
	int valid = -1, cou = 0;
	for(int x = 0; x < 8; x++){
		for(int y = 0; y < 8; y++){
//				printf("---\n");
			if(chess[x][y] == '*'){
//				printf("Ada %d %d\n", x, y);
				cou++;
				valid = check(x, y);
			}
			if(valid == 0) break;
		}
	}
	if(valid == 0) printf("invalid\n");
	else if(cou != 8) printf("invalid\n");
	else printf("valid\n");
	return 0;
}