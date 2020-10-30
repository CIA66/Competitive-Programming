#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
	char value;
	struct data *prev, *next;
};

void pushDpn(struct data **lHead, struct data **lTail, char x){
	
	struct data *nNode = (struct data*)malloc(sizeof(struct data));
	nNode->prev = NULL;
	nNode->next = NULL;
	nNode->value = x;
	
	if(*lHead == NULL){
//		printf("test\n");
		*lHead = *lTail = nNode;
	}
	else {
		nNode->next = *lHead;
		(*lHead)->prev = nNode;
		*lHead = nNode;
	}
}

void popStack(struct data **lHead, struct data **lTail){
	
	// popDpn
	if(*lHead == NULL) return;
	
	if(*lHead == *lTail) {
		free(*lHead);
		*lHead = *lTail = NULL;
	}
	else{
		struct data *toBeDeleted = *lHead;
		*lHead = toBeDeleted->next; 
		(*lTail)->prev = NULL;
		free(toBeDeleted);
	}
}

void popQueue(struct data **lHead, struct data **lTail){
	
	// popBlkg
	if(*lHead == NULL) return;
	
	if(*lHead == *lTail) {
		free(*lHead);
		*lHead = *lTail = NULL;
	}
	else{
		struct data *toBeDeleted = *lTail;
		*lTail = toBeDeleted->prev; 
		(*lTail)->next = NULL;
		free(toBeDeleted);
	}
}


void freeAll(struct data **lHead, struct data **lTail){
	if(*lHead == NULL) return;
	while(*lHead != NULL){
		popStack(lHead, lTail);
	}
}

void printAll(struct data *lHead, struct data *lTail){
	if(lHead == NULL) return;
	
	struct data *currData = lTail;
	while(currData->prev != NULL){
		printf("%c", currData->value);
		currData = currData->prev;
	}
	printf("%c\n", currData->value);
}

int isNumber(char x){
	if('a' <= x && x <= 'z') return 1;
	if ('A' <= x && x <= 'Z') return 1;
	if ('0' <= x && x <= '9') return 1;
	return 0;
}

int isOperator(char x){
	
	if(x == '^') return 1;
	if(x == '*' || x == '/') return 1;
	if(x == '+' || x == '-') return 1;
	return 0;
}

int isLeftAssociative(char x){
	
	if(x == '*' || x == '/') return 1;
	if(x == '+' || x == '-') return 1;
	return 0;
}

int precedence(char x){
	
	if(x == '^') return 4;
	if(x == '*' || x == '/') return 3;
	if(x == '+' || x == '-') return 2;
	return 0;
}

int main(){
	
	struct data *hStack = NULL, *tStack = NULL;
	struct data *hQueue = NULL, *tQueue = NULL;
	
	int T;
	scanf("%d", &T);
	getchar();
	
	for(int q = 0; q < T; q++){
		char token[406];
//			gets(token);
		
		scanf("%[^\n]", token); getchar();
		int len = strlen(token);
		
		for(int i = 0; i < len; i++){
			
			char now = token[i];
			
			if(isNumber(now)){
				pushDpn(&hQueue, &tQueue, now);
				continue;
			}
			
			if(isOperator(now)){
				while( ( (precedence(hStack->value) > precedence(now))
				|| ((precedence(hStack->value) == precedence(now)) && isLeftAssociative(hStack->value))
						) && hStack->value != '('){
					pushDpn(&hQueue, &tQueue, hStack->value);
					popStack(&hStack, &tStack);
				}
				pushDpn(&hStack, &tStack, now);
				continue;
			}
			
			if(now == '('){
				pushDpn(&hStack, &tStack, now);
				continue;
			}
//			printf("test\n");
			
			if(now == ')'){
				while(hStack != NULL && (hStack->value != '(')){
					pushDpn(&hQueue, &tQueue, hStack->value);
					popStack(&hStack, &tStack);
				}
				if(hStack->value == '(')
					popStack(&hStack, &tStack);
					
				continue;
			}
		}
		
		while(hStack != NULL){
			if(isOperator(hStack->value)) pushDpn(&hQueue, &tQueue, hStack->value);
			popStack(&hStack, &tStack);
		}
		printAll(hQueue, tQueue);
		
		freeAll(&hStack, &tStack);
		freeAll(&hQueue, &tQueue);
	}
	
	
	return 0;
}

/*

3
(a+(b*c))
((a+b)*(z+x))
((a+t)*((b+(a+c))^(c+d)))

3+4*2/(1-5)^2^3
*/