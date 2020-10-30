#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
	char value;
	struct data *next, *prev;
};

void pushBack(struct data **lHead, struct data **lTail, char x){
	
	struct data *nNode = (struct data*)malloc(sizeof(struct data));
	nNode->value = x;
	nNode->next = NULL;
	nNode->prev = NULL;
	
	if(*lHead == NULL){
		*lHead = *lTail = nNode;
	}
	else{
		nNode->prev = *lTail;
		(*lTail)->next = nNode;
		*lTail = nNode;
	}
}

void pushDpn(struct data **lHead, struct data **lTail, char x){
	
	struct data *nNode = (struct data*)malloc(sizeof(struct data));
	nNode->value = x;
	nNode->next = NULL;
	nNode->prev = NULL;
	
	if(*lHead == NULL){
		*lHead = *lTail = nNode;
	}
	else{
		nNode->next = *lHead;
		(*lHead)->prev = nNode;
		*lHead = nNode;
	}
}

void pushBeiju(struct data **lHead, struct data **lTail, struct data **cursor, char x){
	
	struct data *nNode = (struct data*)malloc(sizeof(struct data));
	nNode->value = x;
	nNode->next = NULL;
	nNode->prev = NULL;
	
	if((*cursor)->next == NULL){
		(*cursor)->next	= nNode;
		nNode->prev = *cursor;
		*cursor = *lTail = nNode;
	}
	else{
		nNode->prev = *cursor;
		nNode->next = (*cursor)->next;
		(*cursor)->next->prev = nNode;
		(*cursor)->next = nNode;
		*cursor = nNode;
	}
}

void printAll(struct data *lHead){
        if(lHead == NULL) return;
	struct data *currData = lHead;
	while(currData->next != NULL){
		printf("%c", currData->value);
		currData = currData->next;
	}
	printf("%c\n", currData->value);
}


void popDpn(struct data **lHead, struct data **lTail){
	if(*lHead == NULL) return;
	
	if(*lHead == *lTail){
		free(*lHead);
		*lHead = *lTail = NULL;
	}
	else{
		struct data *toBeDeleted = *lHead;
		*lHead = toBeDeleted->next;
		free(toBeDeleted);
	}
}

void freeAll(struct data **lHead, struct data **lTail){
	if(*lHead == NULL) return;
	while(*lHead != NULL){
		popDpn(lHead, lTail);
	}
}

int main(){
	
	char str[100006];
	
	while(scanf("%[^\n]", str) != EOF){
		
		struct data *head = NULL, *tail = NULL;
		struct data *cursor = NULL;
		
		int len = strlen(str);
		int beiju = 0;
		
		for(int i = 0; i < len; i++){
			char now = str[i];
			if(now == '['){
				beiju = 1;
				cursor = head;
			}
			else if(now == ']'){
				beiju = 0;
				cursor = tail;
			}
			else if(('a' <= now && now <= 'z') || ('A' <= now && now <= 'Z') || now == '_'){
				
//			printf("test\n");
				if(head == NULL){
					pushDpn(&head, &tail, now);
					cursor = head;
                                        beiju = 0;
				}
				else if(beiju == 1){
					pushDpn(&head, &tail, now);
					beiju = 0;
					cursor = head;
				}
				else if(beiju == 0){
					pushBeiju(&head, &tail, &cursor, now);
				}
			}
			
		}
		
		printAll(head);
		getchar();
		 
		freeAll(&head, &tail);
	}
	
	return 0;
}

/*

This_is_a_[Beiju]_text
[[]][][]Happy_Birthday_to_Tsinghua_University
thidd[beeee[ijuu[kakka]]]www

*/