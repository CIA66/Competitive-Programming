#include<stdio.h>
#include<stdlib.h>

struct data{
	int angka;
	struct data *prev, *next;
};


void pushHead(struct data **localHead, struct data **localTail, int x){
	struct data *newNode = (struct data*)malloc(sizeof(struct data));
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->angka = x;
	
	if((*localHead) == NULL){
		*localHead = *localTail = newNode;
	}
	else{
		newNode->next = *localHead;
		(*localHead)->prev = newNode;
		*localHead = newNode;
	}
}

void pushTail(struct data **localHead, struct data **localTail, int x){
	struct data *newNode = (struct data*)malloc(sizeof(struct data));
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->angka = x;
	
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

void priorityQueue(struct data **localHead, struct data **localTail, int x){
	struct data *newNode = (struct data*)malloc(sizeof(struct data));
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->angka = x;
	
	if((*localHead) == NULL){
		*localHead = *localTail = newNode;
	}
	else if((*localHead)->angka >= x){
		pushHead(localHead, localTail, x);
	}
	else if((*localTail)->angka <= x){
		pushTail(localHead, localTail, x);
	}
	else{
		struct data *currentLocation = *localHead;
		while(currentLocation != NULL){
			if(currentLocation->angka > x){
				break;
			}
			currentLocation = currentLocation->next;
		}
		newNode->next = currentLocation;
		newNode->prev = currentLocation->prev;
		currentLocation->prev->next = newNode;
		currentLocation->prev = newNode;
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

void printAll(struct data *localHead){
	struct data *currentLocation = localHead;
	if(currentLocation == NULL){
		return;
	}
	else{
		while(currentLocation->next != NULL){
			printf("%d ", currentLocation->angka);
			currentLocation = currentLocation->next;
		}
		printf("%d\n", currentLocation->angka);
	}
}

int main(){
	int N = 0;
	
	while(1){
		scanf("%d", &N);
		if(N == 0) break;
		int num = 0;
		struct data *head = NULL, *tail = NULL;
		for(int a=0; a<N; a++){
			scanf("%d", &num);
			priorityQueue(&head, &tail, num);
		}
//		printAll(head);
		
		int cost = 0, total = 0;
		while(head->next != NULL){
//			printf("curr : %d	", curr->angka);
			cost = head->angka;
			popHead(&head, &tail);
			cost += head->angka;
			popHead(&head, &tail);
			total += cost;
			priorityQueue(&head, &tail, cost);
//			printf("cost : %d	", cost);
//			printf("%d\n", total);
			
		}
		printf("%d\n", total);
	}
	return 0;
}