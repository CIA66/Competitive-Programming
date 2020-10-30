#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node{
	int row;
	int col;
};
struct data{
	struct node currNode;
	struct data *next, *prev;
};

void pushTail(struct data **localHead, struct data **localTail, struct node currNd){
	struct data *nNode = (struct data*)malloc(sizeof(struct data));
	nNode->currNode = currNd;
	nNode->next = NULL;
	nNode->prev = NULL;
	
	if(*localHead == NULL){
		*localHead = nNode;
		*localTail = nNode;
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

char field[106][106];
int visited[106][106];

const int arahRow[] = {-1, -1, -1, 0, 0, 0, +1, +1, +1};
const int arahCol[] = {-1, 0, +1, -1, 0, +1, -1, 0, +1};

int bfs(int r, int c, int m, int n){
	struct data *qHead = NULL;
	struct data *qTail = NULL;
	
	struct node awal;
	awal.col = c;
	awal.row = r;
	
	pushTail(&qHead, &qTail, awal);
	visited[r][c] = 1;
	
	int flag = 0;
	while(qHead != NULL){
		
		struct node s = qHead->currNode;
//		if(flag == 0) flag = 1;
		popHead(&qHead, &qTail);
		
		for(int i=0; i<9; i++){
//			flag == 1;
			if(flag == 0) flag++;
			int nextRow = s.row + arahRow[i];
			int nextCol = s.col + arahCol[i];
			if(nextRow >= 0 && nextRow < m && nextCol >= 0 && nextCol < n){
				if(field[nextRow][nextCol] == '@' && !visited[nextRow][nextCol]){
					flag++;
					struct node nextNode;
					nextNode.row = nextRow;
					nextNode.col = nextCol;
					pushTail(&qHead, &qTail, nextNode);
					visited[nextRow][nextCol] = 1;
				}
			}
		}
		
	}
	if(flag > 0) return flag;
	else return -1;
}

int main(){
	
	int m = 0;
	int n = 0;
	
	scanf("%d %d", &m, &n);
	while(m != 0){
		for(int a=0; a<106; a++){
			strcpy(field[a], "");
			for(int b=0; b<106; b++){
				visited[a][b] = 0;
			}
		}
	
		for(int row = 0 ; row < m ; row++){
			scanf("%s", field[row]);
		}
		int re = 0;
		int count = 0;
		for(int r = 0; r < m; r++){
			for(int c = 0; c < n; c++){
				if(field[r][c] == '@'){
					if(visited[r][c] == 0){
						re = bfs(r, c, m, n);
//						printf("row : %d col : %d re : %d\n", r, c, re);
						if(re > 0) count++;
					}
				}
			}
		}
		
		printf("%d\n", count);
		
		scanf("%d %d", &m, &n);
	}
	
	return 0;
}