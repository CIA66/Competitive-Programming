#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
	char text;
	struct data *next, *prev;
};

void pushBelakang(struct data **localHead, struct data **localTail, char x){
	struct data *newNode = (struct data*)malloc(sizeof(struct data));
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->text = x;
	
	if((*localHead) == NULL){
		*localHead = *localTail = newNode;
	}
	else{
		struct data *currentData = *localTail;
		currentData->next = newNode;
		newNode->prev = currentData;
		*localTail = newNode;
	}
}

void pushHead(struct data **localHead, struct data **localTail, char x){
	struct data *newNode = (struct data*)malloc(sizeof(struct data));
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->text = x;
	
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

void printAll(struct data *localHead){
	struct data *currentLocation = localHead;
	if(currentLocation == NULL){
		return;
	}
	else{
		while(currentLocation->next != NULL){
			printf("%c", currentLocation->text);
			currentLocation = currentLocation->next;
		}
		printf("%c\n", currentLocation->text);
	}
}

void popDepan(struct data **localHead, struct data **localTail){
	if((*localHead) == NULL) return;
	
	if(*localHead == *localTail){
		free(*localHead);
		*localHead = *localTail = NULL;
	}else{
		struct data *toBeDeleted = *localHead;
		*localHead = (*localHead)->next;
		(*localHead)->prev = NULL;
		free(toBeDeleted);
	}
}

void freeAll(struct data **localHead, struct data **localTail){
	if((*localHead) == NULL) return;
	while((*localHead) != NULL){
		popDepan(localHead, localTail);
	}
	
}

void pushBeiju(struct data **localHead, struct data **localTail, struct data **cursor, char x){
	struct data *newNode = (struct data*)malloc(sizeof(struct data));
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->text = x;
//	printf("%c\n",(*cursor)->next->text);
	if((*cursor)->next == NULL){
		(*cursor)->next = newNode;
		newNode->prev = *cursor;
		*cursor = newNode;
		*localTail = newNode;
	}
	else{
//		printf("masuk\n");
		newNode->next = (*cursor)->next;
		newNode->prev = *cursor;
		(*cursor)->next->prev = newNode;
		(*cursor)->next = newNode;
		*cursor = newNode;
	}
	
	
}


char text[100006];

int main(){
	struct data *head = NULL, *tail = NULL;
	
	while(gets(text)){
		int flag = 0;
		int length = strlen(text);
		struct data *cursor = NULL;
		for(int a=0; a<length; a++){
			if(text[a] == '['){
				cursor = head;
				flag = 1;
			}
			else if(text[a] == ']'){
				cursor = tail;
				flag = 0;
			}
			else if(head == NULL){
				pushBelakang(&head,&tail,text[a]);
				cursor = head;
				flag = 0;
			}
			else{
				if(flag == 0){
					pushBeiju(&head, &tail, &cursor,text[a]);
				}
				else if(flag == 1){
					pushHead(&head,&tail,text[a]);
					cursor = head;
					flag = 0;
				}
			}
//			printAll(head);
				
		}
//			printf("head = ");
//			printAll(head);
//			printf("\n");
//			printf("newHead = ");
//			printAll(newHead);
//			printf("\n");
			printAll(head);
			freeAll(&head, &tail);
		}
		
	
	return 0;
	
}