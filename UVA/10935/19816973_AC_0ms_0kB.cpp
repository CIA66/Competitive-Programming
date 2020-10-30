#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
	int value;
	struct data *prev, *next;
};

void pushTail(struct data **localHead, struct data **localTail, int x){
	struct data *newNode = (struct data*)malloc(sizeof(struct data));
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->value = x;
	
	if((*localHead) == NULL){
		*localHead = *localTail = newNode;
	}
	else{
		struct data *currentLocation = *localTail;
		currentLocation->next = newNode;
		newNode->prev = currentLocation;
		*localTail = newNode;
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


int main(){
	
	int N = 0;
	while(1){
		scanf("%d", &N);
		if(N == 0) break;
		struct data *head = NULL, *tail = NULL;
		for(int a=1; a<=N; a++){
			pushTail(&head, &tail, a);
		}
		printf("Discarded cards:");
		int temp = 0;
		while(head->next != NULL){
			printf(" %d", head->value);
			popHead(&head, &tail);
			temp = head->value;
			popHead(&head, &tail);
			if(head != NULL){
				printf(",");
			}
			pushTail(&head, &tail, temp);
		}
		printf("\nRemaining card:");
		printf(" %d\n", head->value);
		popHead(&head, &tail);
	}	
	return 0;
}