// E

#include<bits/stdc++.h>

using namespace std;

int check(char c, int r){
	// 0 black, 1 white
	if(c == 'A' && (r%2 == 1)) return 0;
	else if(c == 'B' && (r%2 == 0)) return 0;
	else if(c == 'C' && (r%2 == 1)) return 0;
	else if(c == 'D' && (r%2 == 0)) return 0;
	else if(c == 'E' && (r%2 == 1)) return 0;
	else if(c == 'F' && (r%2 == 0)) return 0;
	else if(c == 'G' && (r%2 == 1)) return 0;
	else if(c == 'H' && (r%2 == 0)) return 0;
	else return 1;
}

int charTOint(char c){
	if(c == 'A') return 1;
	else if(c == 'B') return 2;
	else if(c == 'C') return 3;
	else if(c == 'D') return 4;
	else if(c == 'E') return 5;
	else if(c == 'F') return 6;
	else if(c == 'G') return 7;
	else if(c == 'H') return 8;
}

char intTOchar(int c){
	if(c == 1) return 'A';
	else if(c == 2) return 'B';
	else if(c == 3) return 'C';
	else if(c == 4) return 'D';
	else if(c == 5) return 'E';
	else if(c == 6) return 'F';
	else if(c == 7) return 'G';
	else if(c == 8) return 'H';
	else return '-';
}

void solve(char cS, int rS, char cE, int rE){
	int cT; int rT;
	int colS = charTOint(cS);
	int colE = charTOint(cE);
	
	int startRow = 1, startCol = 0;
	int bw = check(cS, rS);
	
	
	int dirX[] = {+1, +1, -1, -1};
	int dirY[] = {+1, -1, +1, -1};
	int find = 0, rr = 0, cc = 0;
	for(int r = startRow; r <= 8; r++){
		if(bw == 1){
			// putih
			if(r % 2 == 1){
				startCol = 2;
			}
			else{
				startCol = 1;
			}
			
		}
		else{
			if(r % 2 == 1){
				startCol = 1;
			}
			else{
				startCol = 2;
			}
		}
		
		for(int c = startCol; c <= 8; c += 2){
			find = 0;
//			printf("Now: %d %d\n", r, c);
			if((r == rS && c == colS) || (r == rE && c == colE)){
				find = 1;
			}
			for(int i = 1; i <= 8; i++){
				for(int j = 0; j < 4; j++){
					int nowC = c + (dirX[j]*i);
					int nowR = r + (dirY[j]*i);
					
					if(nowC > 0 && nowC < 9 && nowR > 0 && nowR < 9){
//						printf("%d %d\n", nowR, nowC);
						if(((nowC == colS) && (nowR == rS)) || ((nowC == colE) && (nowR == rE))){
							find++;
						}
						if(find == 2){
							rr = r; cc = c;
							break;
						}
					}
				}
				if(find == 2) break;
			}
			if(find == 2) break;
		}
		if(find == 2) break;
	}
	
	int segaris = 0;
	for(int i = 1; i <= 8; i++){
		for(int j = 0; j < 4; j++){
			int ccc = colS + (dirX[j]*i);
			int rrr = rS + (dirY[j]*i);
			if(ccc > 0 && ccc < 9 && rrr > 0 && rrr < 9){
				if((ccc == colS && rrr == rS) || (ccc == colE && rrr == rE)){
					segaris = 1;
					break;
				}
			}
		}
		if(segaris == 1) break;
	}
	
	if(segaris == 1){
		printf("1 %c %d %c %d\n", cS, rS, cE, rE);
	}
	else{
		
//		printf("-- %d %d\n", cc, rr);
		printf("2 %c %d %c %d %c %d\n", cS, rS, intTOchar(cc), rr, cE, rE);
	}
	
}

int main(){
	
	int T;
	scanf("%d", &T); getchar();
	
	int rS, rE;
	char cS, cE;
	char str[100];
	while(T--){
		scanf("%[^\n]", str); getchar();
		
//		scanf("%c %d %c %d", cS, &rS, &cE, &rE); getchar();
		
		cS = str[0];
		cE = str[4];
		rS = (int)(str[2] - '0');
		rE = (int)(str[6] - '0');
		
//		printf("%c %d %c %d\n", cS, rS, cE, rE);
//		printf("%d %d\n", check(cS, rS), check(cE, rE));
		if((cS == cE) && (rS == rE)){
			printf("0 %c %d\n", cS, rE);
		}
		else if(check(cS, rS) != check(cE, rE)){
			printf("Impossible\n");
		}
		else{
			solve(cS, rS, cE, rE);
		}
		
		
	}
	return 0;
}