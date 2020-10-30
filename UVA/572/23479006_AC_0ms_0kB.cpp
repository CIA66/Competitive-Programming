#include<stdio.h>
#include<stdlib.h>

#define sd struct data

struct data{
	int x, y;
	struct data *next, *prev;
};

void pushBack(sd **lHead, sd **lTail, int a, int b){
	
	sd *nNode = (sd*)malloc(sizeof(sd));
	nNode->x = a;
	nNode->y = b;
	nNode->next = NULL;
	nNode->prev = NULL;
	
	if(*lHead == NULL) *lHead = *lTail = nNode;
	else{
		nNode->prev = *lTail;
		(*lTail)->next = nNode;
		*lTail = nNode;
	}
}

void popDpn(sd **lHead, sd **lTail){
	
	if(*lHead == NULL) return;
	
	if(*lHead == *lTail){
		free(*lHead);
		*lHead = *lTail = NULL;
	}
	else{
		sd *tBD = *lHead;
		*lHead = tBD->next;
		free(tBD);
		(*lHead)->prev = NULL;
	}
}

void freeAll(sd **lHead, sd **lTail){
	if(*lHead == NULL) return;
	
	while(*lHead != NULL){
		popDpn(lHead, lTail);
	}
}

int visited[106][106];
char map[106][106];

const int dirX[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dirY[] = {0, 0, 1, -1, 1, -1, 1, -1};


void bfs(int i, int j, int m, int n){
	
	sd *head = NULL, *tail = NULL;
	
	pushBack(&head, &tail, i, j);
	visited[i][j] = 1;
	
	while(head != NULL){
		
		int row = head->x;
		int col = head->y;
		popDpn(&head, &tail);
		
		for(int i = 0; i < 8; i++){
			int xx = row + dirX[i];
			int yy = col + dirY[i];
			if(xx >= 0 && xx < m && yy >= 0 && yy < n){
				if(!visited[xx][yy] && map[xx][yy] == '@'){
					pushBack(&head, &tail, xx, yy);
					visited[xx][yy] = 1;
				}
			}
		}
	}
}

int main(){
	
	int m, n;
	while(1){
		scanf("%d %d", &m, &n);
		if(m == 0) break;
		
		for(int q = 0; q < m; q++){
			for(int w = 0; w < n; w++){
				visited[q][w] = 0;
			}
		}
		
		for(int i = 0; i < m; i++){
			scanf("%s", map[i]);
		}
		
		int count = 0;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(map[i][j] == '@' && !visited[i][j]){
					bfs(i, j, m, n);
					count++;
				}
			}
		}
		
		printf("%d\n", count);
	}
	
	
	return 0;
}

/*

1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
0 0

*/
