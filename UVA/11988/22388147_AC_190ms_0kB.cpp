#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define sd struct data

struct data{
	
	char value;
	struct data *next, *prev;
};

void pushBack(sd **lHead, sd **lTail, char x){
	
	sd *nNode = (sd*)malloc(sizeof(sd));
	nNode->next = NULL;
	nNode->prev = NULL;
	nNode->value = x;
	
	if(*lHead == NULL) *lHead = *lTail = nNode;
	else{
		nNode->prev = *lTail;
		(*lTail)->next = nNode;
		*lTail = nNode;
	}
}

void pushDpn(sd **lHead, sd **lTail, char x){
	
	sd *nNode = (sd*)malloc(sizeof(sd));
	nNode->value = x;
	nNode->next = NULL;
	nNode->prev = NULL;
	
	if(*lHead == NULL) *lHead = *lTail = nNode;
	else{
		nNode->next = *lHead;
		(*lHead)->prev = nNode;
		*lHead = nNode;
	}
}

void pushBeiju(sd **lHead, sd **lTail, sd **curr, char x){
	
	sd *nNode = (sd*)malloc(sizeof(sd));
	nNode->value = x;
	nNode->next = NULL;
	nNode->prev = NULL;
	
	if((*curr)->next == NULL){
		nNode->prev = *curr;
		(*curr)->next = nNode;
		*curr = *lTail = nNode;
	}
	else{
		nNode->next = (*curr)->next;
		nNode->prev = *curr;
		(*curr)->next->prev = nNode;
		(*curr)->next = nNode;
		*curr = nNode;
	}
}

void printAll(sd *lHead){
	if(lHead == NULL) return;
	sd *currData = lHead;
	
	while(currData->next != NULL){
		printf("%c", currData->value);
		currData = currData->next;
	}
	printf("%c\n", currData->value);
}

void popDpn(sd **lHead, sd **lTail){
	
	if(*lHead == NULL) return;
	
	if(*lHead == *lTail){
		free(*lHead);
		*lHead = *lTail = NULL;
	}
	else{
		struct data *toBeDeleted = *lHead;
		*lHead = (*lHead)->next;
		(*lHead)->prev = NULL;
		free(toBeDeleted);
	}
}

void freeAll(sd **lHead, sd **lTail){
	if(*lHead == NULL) return;
	
	while(*lHead != NULL){
		popDpn(lHead, lTail);
	}
}

char str[100006];

int main(){
	
	sd *head = NULL, *tail = NULL;
	
	
	while(scanf("%s", str) != EOF){
		
		int len = strlen(str);
		sd *curr = NULL;
		int beiju = 0;
		
		for(int i = 0; i < len; i++){
//			char now = str[i];
			
			if(str[i] == '['){
				curr = head;
				beiju = 1;
			}
			else if(str[i] == ']'){
				curr = tail;
				beiju = 0;
			}
			else if(head == NULL){
				pushBack(&head, &tail, str[i]);
				curr = head;
				beiju = 0;
			}
			else{
				
				if(beiju){
					pushDpn(&head, &tail, str[i]);
					curr = head;
					beiju = 0;
				}
				else if(!beiju){
					pushBeiju(&head, &tail, &curr, str[i]);
				}
			}
			
		}
		
		printAll(head);
		freeAll(&head, &tail);
		
	}
	
	return 0;
}


/*

This_is_a_[Beiju]_text
[[]][][]Happy_Birthday_to_Tsinghua_University
thidd[beeee[ijuu[kakka]]]www

*/