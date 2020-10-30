#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data {
	char value;
	struct data *next;
	struct data *prev;
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
		*localHead = NULL;
		*localTail = NULL;
	}
	else{
		*localHead = (*localHead)->next;
		free((*localHead)->prev);
		(*localHead)->prev = NULL;
	}
}

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

void printAll(struct data *localHead){
	struct data *currentLocation = localHead;
	
	if(currentLocation == NULL) return;
	
	else{
		while(currentLocation->next != NULL){
			printf("%c", currentLocation->value);
			currentLocation = currentLocation->next;
		}
		printf("%c\n", currentLocation->value);
	}
}

void freeAll(struct data **localHead, struct data **localTail){
	if(*localHead == NULL) return;
	while((*localHead) != NULL){
		popHead(localHead, localTail);
	}
}

int operatorPrecedence(char x){
	if(x == '*' || x == '/') return 3;
	if(x == '+' || x == '-') return 2;
	return 1;
}

int main(){
	
	int T;
	
	scanf("%d", &T); getchar(); getchar();
	for(int a=0; a<T; a++){
		
		char chr;		
		struct data *stHead = NULL;
		struct data *stTail = NULL;
		struct data *qHead = NULL;
		struct data *qTail = NULL;
		
		while(scanf("%c", &chr) != EOF){
			if(chr == '\n'){
				break;
				getchar();
			}
			
			if(chr == '('){
				pushHead(&stHead, &stTail, chr);
			}
			else if(chr == ')'){
				while(stHead != NULL && (stHead->value != '(')){
//					printf("_%c\n", stHead->value);
					pushTail(&qHead, &qTail, stHead->value);
					popHead(&stHead, &stTail);
				}
				if(stHead != NULL && stHead->value == '('){
					popHead(&stHead, &stTail);
				}
			}
			else if('0' <= chr && chr <= '9'){
//				printf("_%c\n", chr);
				pushTail(&qHead, &qTail, chr);
			}
			else{
				
				while(stHead != NULL && ((operatorPrecedence(stHead->value) > operatorPrecedence(chr)) || (operatorPrecedence(stHead->value) == operatorPrecedence(chr)) )&& (stHead->value != '(')){
//					printf("_%c\n", stHead->value);
					pushTail(&qHead, &qTail, stHead->value);
					popHead(&stHead, &stTail);
				}
				pushHead(&stHead, &stTail, chr);
			}
			getchar();
			
		}
		
		while(stHead != NULL){
//			printf("_%c\n", stHead->value);
			pushTail(&qHead, &qTail, stHead->value);
			popHead(&stHead, &stTail);
		}
		
		printAll(qHead);
//		freeAll(&qHead, &qTail);
//		printf("a = %d\n", a);
		if(a != (T-1)) printf("\n");
//		getchar();
	}
	return 0;
}