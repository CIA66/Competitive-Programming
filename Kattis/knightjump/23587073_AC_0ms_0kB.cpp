#include<stdio.h>
#include<stdlib.h>

struct koordinat{
	int row, col;
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

int visited[106][106];
char chess[106][106];

const int arahRow[] = {+2, +2, -2, -2, +1, +1, -1, -1};
const int arahCol[] = {+1, -1, +1, -1, +2, -2, +2, -2};

int bfs(struct koordinat awal, int bykRow, int bykCol){
	struct data *qHead = NULL, *qTail = NULL;
	
	for(int a = 0; a < 101; a++){
		for(int b = 0; b < 101; b++){
			visited[a][b] = 0;
		}
	}
	
	awal.count = 0;
	
	pushTail(&qHead, &qTail, awal);
	visited[awal.row][awal.col] = 1;
	
	
	while(qHead != NULL){
		
		
		struct koordinat s = qHead->currKoor;
		popHead(&qHead, &qTail);
		
		for(int i=0; i<8; i++){
			int nextRow = s.row + arahRow[i];
			int nextCol = s.col + arahCol[i];
			if(nextRow >= 0 && nextCol >= 0
				 && nextRow < bykRow && nextCol < bykCol
				 && !visited[nextRow][nextCol] 
				 && chess[nextRow][nextCol] != '#'){
				
				if (nextRow == 0 && nextCol == 0){
					return s.count;
				}
				else if(chess[nextRow][nextCol] == '.'){
					struct koordinat nextKoordinat;
					nextKoordinat.row = nextRow;
					nextKoordinat.col = nextCol;
					nextKoordinat.count = s.count+1;
					
					pushTail(&qHead, &qTail, nextKoordinat);
					visited[nextRow][nextCol] = 1;
				}
			}
		}
		
	}
	
	return -2;
}


int main(){
	
	int N;
	
	scanf("%d", &N); getchar();
	
	
	for(int row = 0; row < N; row++){
		for(int col = 0; col < N; col++){
			chess[row][col] = '#';
		}
	}
	
	int found = 0;
	struct koordinat awal;
	
	for(int i = 0; i < N; i++){
		scanf("%s", &chess[i]);
	}

	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(chess[i][j] == 'K'){
				found = 1;
				
				awal.row = i;
				awal.col = j;
				break;
			}
		}
		if(found) break;
	}
	if(awal.row == 0 && awal.col == 0) printf("0\n");
	else printf("%d\n", bfs(awal, N, N) + 1);
	
	return 0;
}

/*

4
....
....
....
...K


3
..K
...
###

4
K...
....
....
....


*/