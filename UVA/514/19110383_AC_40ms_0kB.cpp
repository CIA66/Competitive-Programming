#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
	int value;
	struct data *next, *prev;
};

void pushTail(struct data **localHead, struct data **localTail, char x){
	struct data *newNode = (struct data*)malloc(sizeof(struct data));
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->value = x;
	
	if((*localHead) == NULL){
		*localHead = newNode;
		*localTail = newNode;
	}
	else{
		(*localTail)->next = newNode;
		newNode->prev = *localTail;
		*localTail = (*localTail)->next;
	}
}

void popTail(struct data **localHead, struct data **localTail){
	if((*localHead) == NULL) return;
	
	if(*localHead == *localTail){
		free(*localHead);
		*localHead = *localTail = NULL;
	}
	else{
		*localTail = (*localTail)->prev;
		free((*localTail)->next);
		(*localTail)->next = NULL;
	}
}

void popHead(struct data **localHead, struct data **localTail){
	if((*localHead) == NULL) return;
	
	if(*localHead == *localTail){
		free(*localHead);
		*localHead = *localTail = NULL;
	}
	else{
		*localHead = (*localHead)->next;
		free((*localHead)->prev);
		(*localHead)->prev = NULL;
	}
}

void pushHead(struct data **localHead, struct data **localTail, int x){
	struct data *newNode = (struct data*)malloc(sizeof(struct data));
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->value = x;
	
	if((*localHead) == NULL){
		*localHead = *localTail = newNode;
	}
	else{
		newNode->next = *localHead;
		(*localHead)->prev = newNode;
		*localHead = newNode;
	}
}

void freeAll(struct data **localHead, struct data **localTail){
	if(*localHead == NULL) return;
	while((*localHead) != NULL){
		popHead(localHead, localTail);
	}	
}

int main(){
	struct data *head = NULL;
	struct data *tail = NULL;
	
	int N = 0;
	scanf("%d", &N); getchar();
	while(true){
		if(N == 0){
			getchar();
			break;
		}
//		printf("%d\n", N);
		int deret[1006];
		int stop = 0;
		while(true){
			for(int a=0; a<N; a++){
				scanf("%d", &deret[a]); //getchar();
				if(deret[0] == 0){
					stop = 1;
					break;
				}
			}
			if(stop == 1){
				printf("\n");
				break;
			}
			
			int flag = 0;
			int idx = 0;
			for(int i=1; i<=N ; ){
				
				pushHead(&head, &tail, i);
				
				while(head != NULL && head->value == deret[idx]){
					popHead(&head, &tail);
					idx++;
					if(idx >= N) break;
				}
				i++;
			}
			if(head != NULL){
				printf("No\n");
				freeAll(&head, &tail);
			}else{
				printf("Yes\n");
			}
		}
		scanf("%d", &N);			
	}
	
	
	return 0;
}