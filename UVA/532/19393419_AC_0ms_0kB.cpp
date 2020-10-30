#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct koordinat{
	int lt, row, col;
	int count;
};

struct data{
	struct koordinat currKoor;
	struct data *prev, *next;
};

void pushTail(struct data **localHead, struct data **localTail, struct koordinat currKo){
	struct data *nNode = (struct data*)malloc(sizeof(struct data));
	nNode->currKoor = currKo;
	nNode->next = NULL;
	nNode->prev = NULL;
	
	if(*localHead == NULL){
		*localHead = *localTail = nNode;
	} else {
		(*localTail)->next = nNode;
		nNode->prev = *localTail;
		*localTail = nNode;
	}
}

void popHead(struct data **localHead, struct data **localTail){
	if(*localHead == NULL) return;
	
	if(*localHead == *localTail){
		free(*localHead);
		*localHead = *localTail = NULL;
	} else {
		*localHead = (*localHead)->next;
		free((*localHead)->prev);
		(*localHead)->prev = NULL;
	}
}

char map[31][31][31];
int visited[31][31][31];
// north, south, east, west, up, down
const int arahLnt[] = {0, 0, 0, 0, +1, -1};
const int arahRow[] = {-1, +1, 0, 0, 0, 0};
const int arahCol[] = {0, 0, +1, -1, 0, 0}; 

int bfs(struct koordinat awal, int bykLantai, int bykRow, int bykCol){
	struct data *qHead = NULL, *qTail = NULL;
	
	for(int a = 0; a < 31; a++){
		for(int b = 0; b < 31; b++){
			for(int c = 0; c < 31; c++){
				visited[a][b][c] = 0;
			}
		}
	}
	
	awal.count = 0;
	
	pushTail(&qHead, &qTail, awal);
	visited[awal.lt][awal.row][awal.col] = 1;
	
	
	while(qHead != NULL){
		struct koordinat s = qHead->currKoor;
		
		popHead(&qHead, &qTail);
		
		for(int i=0; i<6; i++){
			int nextLnt = s.lt + arahLnt[i];
			int nextRow = s.row + arahRow[i];
			int nextCol = s.col + arahCol[i];
			if(nextLnt >= 0 && nextRow >= 0 && nextCol >= 0 && nextLnt < bykLantai && nextRow < bykRow && nextCol < bykCol && !visited[nextLnt][nextRow][nextCol]){
				
				if(map[nextLnt][nextRow][nextCol] == '.'){
					struct koordinat nextKoordinat;
					nextKoordinat.lt = nextLnt;
					nextKoordinat.row = nextRow;
					nextKoordinat.col = nextCol;
					nextKoordinat.count = s.count+1;
					
					pushTail(&qHead, &qTail, nextKoordinat);
					visited[nextLnt][nextRow][nextCol] = 1;
				}
				else if (map[nextLnt][nextRow][nextCol] == 'E'){
					return s.count;
				}
			}
		}
		
	}
	return -1;
}

int main(){
	int bykLantai = 0, bykRow = 0, bykCol = 0;
	
	while(scanf("%d %d %d", &bykLantai, &bykRow, &bykCol)){
		getchar();
		if(bykLantai == 0 && bykRow == 0 && bykCol == 0) break;
		
		for(int lt = 0; lt < bykLantai; lt++){
			for(int row = 0; row < bykRow; row++){
				for(int col = 0; col < bykCol; col++){
					map[lt][row][col] = '#';
				}
			}
		}
		
		struct koordinat awal;
		int startLantai = 0, startRow = 0, startCol = 0;
		for(int lt = 0; lt < bykLantai; lt++){
			for(int row = 0; row < bykRow; row++){
				scanf("%s", map[lt][row]);
				for(int col = 0; col < bykCol ; col++){
					if(map[lt][row][col] == 'S'){
						awal.lt = lt;
						awal.row = row;
						awal.col = col;
					}					
				}
//				getchar();
			}
			getchar();
		}
		
		int x = bfs(awal, bykLantai, bykRow, bykCol) + 1;
		
		if(x > 0){
			printf("Escaped in %d minute(s).\n", x);
		} else {
			printf("Trapped!\n");
		}
	}
	return 0;
}