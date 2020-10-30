#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data{
	int T;
	int operation;
	int angka;
	struct data *prev, *next;
};


void pushBlkg(struct data **localHead, struct data **localTail, int x){
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

void popBlkg(struct data **localHead, struct data **localTail){
	if((*localHead) == NULL) return;
	
	struct data *toBeDeleted = *localTail;
	if(*localHead == *localTail){
		free(*localHead);
		*localHead = *localTail = NULL;
	}
	else{
		struct data *currData = *localTail;
		struct data *prevData = NULL;
		
		prevData = currData->prev;
		prevData->next = NULL;
		*localTail = prevData;
		free(currData);
	}
}

void popDpn(struct data **localHead, struct data **localTail){
	if((*localHead) == NULL) return;
	
	if(*localHead == *localTail){
		free(*localHead);
		*localHead = *localTail = NULL;
	}
	else{
		struct data *toBeDeleted = *localHead;
		*localHead = (*localHead)->next;
		(*localHead)->prev = NULL;
		free(toBeDeleted);
	}
}

void pushDpn(struct data **localHead, struct data **localTail, int x){
	struct data *newNode = (struct data*)malloc(sizeof(struct data));
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->angka = x;
	
	if((*localHead) == NULL){
		*localHead = *localTail = newNode;
	}
	else{
		struct data *currentLocation = *localHead;
		currentLocation->prev = newNode;
		newNode->next = currentLocation;
		*localHead = newNode;
	}
}

void prioQ(struct data **localHead, struct data **localTail, int x){
	struct data *newNode = (struct data*)malloc(sizeof(struct data));
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->angka = x;
	
	if((*localHead) == NULL){
		*localHead = *localTail = newNode;
	}
	else if((*localHead)->angka >= x){
		pushDpn(localHead, localTail, x);
	}
	else if((*localTail)->angka <= x){
		pushBlkg(localHead, localTail, x);
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

void freeAll(struct data **localHead, struct data **localTail){
	if(*localHead == NULL) return;
	while((*localHead) != NULL){
		popDpn(localHead, localTail);
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
	struct data *headStack = NULL, *tailStack = NULL;
	struct data *headQueue = NULL, *tailQueue = NULL;
	struct data *headPrio = NULL, *tailPrio = NULL;
	
	int T = 0;
	int operation = 0;
	int angka = 0;

	
	while((scanf("%d", &T)) != EOF){
			
	int flagStack = 1;
	int flagQueue = 1;
	int flagPrio = 1;
	headStack = NULL;
	tailStack = NULL;
	headQueue = NULL;
	tailQueue = NULL;
	headPrio = NULL;
	tailPrio = NULL;
	
		for(int a=0; a<T; a++){
			scanf("%d %d", &operation, &angka);
			if(operation == 1){
				pushBlkg(&headStack, &tailStack, angka);
				pushBlkg(&headQueue, &tailQueue, angka);
				prioQ(&headPrio, &tailPrio, angka);
			}
			else if(operation == 2){
				if(flagStack == 1){
					if((headStack) == NULL){
						flagStack = 0;
					}
					else if((tailStack)->angka != angka){
						flagStack = 0;
					}else{
						popBlkg(&headStack, &tailStack);
					}
					
				}
				if(flagQueue == 1){
					if(headQueue == NULL){
						flagQueue = 0;
					}
					else if((headQueue)->angka != angka){
						flagQueue = 0;
					}else{
						popDpn(&headQueue, &tailQueue);
					}
					
				}
				if(flagPrio == 1){
					if(headPrio == NULL){
						flagPrio = 0;
					}else if((tailPrio)->angka != angka){
						flagPrio = 0;
					}else{
						popBlkg(&headPrio, &tailPrio);
					}
				}
				
			}
//				printAll(headStack);
//				printAll(headQueue);
//				printAll(headPrio);
			
		}
		if(flagStack == 1 && flagQueue == 0 && flagPrio == 0){
			printf("stack\n");
		}else if(flagStack == 0 && flagQueue == 1 && flagPrio == 0){
			printf("queue\n");
		}else if(flagStack == 0 && flagQueue == 0 && flagPrio == 1){
			printf("priority queue\n");
		}else if(flagStack == 0 && flagQueue == 0 && flagPrio == 0){
			printf("impossible\n");
		}else{
			printf("not sure\n");
		}
		freeAll(&headStack, &tailStack);
		freeAll(&headQueue, &tailQueue);
		freeAll(&headPrio, &tailPrio);
	}
	
	return 0;
}