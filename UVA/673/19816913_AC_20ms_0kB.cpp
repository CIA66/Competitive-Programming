#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
	char value;
	struct data *prev, *next;
};

void pushHead(struct data **localHead, struct data **localTail, char x){
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

void freeAll(struct data **localHead, struct data **localTail){
	if(*localHead == NULL) return;
	while((*localHead) != NULL){
		popHead(localHead, localTail);
	}
}


int main(){
	
	char str[130];
	int T = 0;
	strcpy(str, "");
	scanf("%d", &T); getchar();
	for(int a=0; a<T; a++){
		gets(str);
		int len = strlen(str);
		struct data *head = NULL, *tail = NULL;
		for(int b=0; b<len; b++){
			if(str[b] == '(' || str[b] == '['){
				pushHead(&head, &tail, str[b]);
			} else if( str[b] == ')'){
				if(head == NULL || head->value != '('){
//					printf("test\n");
					pushHead(&head, &tail, '*');
					break;
				} 
				popHead(&head, &tail);
				
			} else if(str[b] == ']'){
				if(head == NULL || head->value != '['){
					pushHead(&head, &tail, '*');
//					printf("test\n");
					break;
				} 
				popHead(&head, &tail);
			}
		}
		strcpy(str, "");
		if(head == NULL) printf("Yes\n");
		else printf("No\n");
		freeAll(&head, &tail);
	}
	
	
	return 0;
}