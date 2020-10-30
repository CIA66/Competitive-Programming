#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
	int row;
	int col;
	int count;
};

struct data{
//	int row;
//	int col;
//	int count;
	struct node currNode;
	struct data *next;
	struct data *prev;
};

void printAll(struct data *localHead){
	
	struct data *curr = localHead;
	printf("PRINT : ");
	while(curr){
		printf("%d ",curr->currNode.count);
		curr = curr->next;
	}
	printf("\n");
}

int countData;

void pushTail(struct data **localHead, struct data **localTail, struct node currNd){
	struct data *newNode = (struct data*)malloc(sizeof(struct data));
	
	newNode->currNode = currNd;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	if(*localHead == NULL){
		*localHead = newNode;
		*localTail = newNode;
	}
	else{
		(*localTail)->next = newNode;
		newNode->prev = *localTail;
		*localTail = newNode;
	}
	countData++;
	
}

void popHead(struct data **localHead, struct data **localTail){
	if(*localHead == NULL) return;
	
	if(*localHead == *localTail){
		free(*localHead);
		*localHead = NULL;
		*localTail = NULL;
	}
	else{
		*localHead = (*localHead)->next;
		free((*localHead)->prev);
		(*localHead)->prev = NULL;
	}
	countData--;
}

void freeAll(struct data **localHead, struct data **localTail){
	while(*localHead != NULL){
		popHead(localHead, localTail);
	}
}

int map[9][9];

int visited[9][9];

const int arahRow[] = {-1, -1, 1, 1, -2, -2, 2, 2};
const int arahCol[] = {-2, 2, -2, 2, -1, 1, -1, 1};

int bfs(int toRow, int toCol, int row, int col){
	struct data *qHead = NULL;
	struct data *qTail = NULL;
	
	for(int a=0; a<8; a++){
		for(int b=0; b<8; b++){
			visited[a][b] = 0;
		}
	}
	
	int count = 0;

	struct node awal;
//	cur.node = map[row][col], cur.count = count;
	awal.row = row;
	awal.col = col;
	awal.count = 0;
	
	struct node akhir;
	akhir.row = toRow;
	akhir.col = toCol;
	
	pushTail(&qHead, &qTail, awal);
	visited[row][col] = 1;
					

	while(qHead != NULL){
		struct node s = qHead->currNode;
		
		popHead(&qHead, &qTail);
		if(s.col == akhir.col && s.row == akhir.row){
			return s.count;
		}	
		
		
		// kuda berjalan
		for(int i=0; i<8; i++){
			int knightRow = s.row + arahRow[i];
			int knightCol = s.col + arahCol[i];
			if(knightCol >= 0 && knightCol < 8 && knightRow >=0 && knightRow < 8 && !visited[knightRow][knightCol]){
				struct node nextNode;
				nextNode.row = knightRow;
				nextNode.col = knightCol;
				nextNode.count = s.count+1;
				pushTail(&qHead, &qTail, nextNode);
				visited[knightRow][knightCol] = 1;
			}
		}
//		printAll(qHead);
	}
	return -1;
}

int main(){
	
	char input1[3];
	char input2[3];
	
	int from = 0;
	int to = 0;
	
	while(scanf("%s %s", input1, input2) != EOF){
		int count = 0;
		int col = input1[0] - 'a';
		int row = input1[1] - '1';
		
		int toCol = input2[0] - 'a';
		int toRow = input2[1] - '1';
		
		if(col == toCol && row == toRow){
			count = 0;
		}
		else{
			count = bfs(toRow, toCol, row, col);
		}
		printf("To get from %s to %s takes %d knight moves.\n", input1, input2, count);
	}
	
	return 0;
}