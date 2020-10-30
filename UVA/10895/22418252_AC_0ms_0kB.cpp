#include<stdio.h>
#include<stdlib.h>

struct data{
	int value;
	int col;
	struct data *next, *prev;
};

void pushData(struct data **lHead, struct data **lTail, int val, int col){
	
	struct data *nNode = (struct data*)malloc(sizeof(struct data));
	nNode->value = val;
	nNode->col = col;
	nNode->next = NULL;
	nNode->prev = NULL;
	
	if(*lHead == NULL) *lHead = *lTail = nNode;
	else{
		nNode->prev = *lTail;
		(*lTail)->next = nNode;
		*lTail = nNode;
	}
}

void pop(struct data **lHead, struct data **lTail){
	if(*lHead == NULL) return;
	if(*lHead == *lTail){
		free(*lHead);
		*lHead = *lTail = NULL;
	}
	else{
		struct data *TBD = *lHead;
		*lHead = TBD->next;
		(*lHead)->prev = NULL;
		free(TBD);
	}
}

void popAll(struct data **lHead, struct data **lTail){
	if(*lHead == NULL) return;
	while(*lHead != NULL){
		pop(lHead, lTail);
	}
}

int main(){
	
	
	
	int m, n;
	
	while(scanf("%d %d", &m, &n) != EOF){
	
	
		struct data *head[100], *tail[100];
		int size[100];
		
		for(int i = 0; i < 85; i++){
			head[i] = tail[i] = NULL;
			size[i] = 0;
		}
	
	
		int r, tempRow[100];
		for(int col = 1; col <= m; col++){
			
			
			scanf("%d", &r);
			for(int i = 1; i <= r; i++){
				scanf("%d", &tempRow[i]);
				size[tempRow[i]]++;
			}
			
			for(int i = 1; i <= r; i++){
				int x; scanf("%d", &x);
				pushData(&head[tempRow[i]], &tail[tempRow[i]], x, col);
			}
		}
		
	//	printf("----\n");
	//	for(int i = 1; i <= r; i++){
	//		
	//		printf("tempRow[i] : %d\n", tempRow[i]);
	//		printf("size head ke %d : %d\n", i, size[tempRow[i]]);
	//		
	//		struct data *c = head[i];
	//		if(head[i] == NULL) continue;
	//		while(c->next != NULL){
	//			printf("%d ", c->value);
	//			c = c->next;
	//		}
	//		printf("%d\n", c->value);
	//	}
	//	
	//	printf("----\n");
		
		printf("%d %d\n", n, m);
		for(int i = 1; i <= n; i++){
	//		printf("_");
			if(head[i] == NULL){
				printf("0\n");
				printf("\n");
			}else{
				printf("%d ", size[i]);
				struct data *curr = head[i];
				while(curr->next != NULL){
					printf("%d ", curr->col);
					curr = curr->next;
				}
				if(curr != NULL) printf("%d\n", curr->col);
				
				struct data *currVal = head[i];
				while(currVal->next != NULL){
					printf("%d ", currVal->value);
					currVal = currVal->next;
				}
				if(curr != NULL) printf("%d\n", currVal->value);
			}
			
		}
	}
	return 0;
}


/*

4 3
3 1 2 3
1 3 2
2 2 3
4 -1
0
3 1 2 3
5 -2 11

*/