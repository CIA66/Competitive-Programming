#include<stdio.h>
#include<stdlib.h>

struct data{
	int value;
	struct data *next, *prev;
}*head[300005], *tail[300005];

void pushTail(int s, int v){
	struct data *newNode = (struct data*)malloc(sizeof(struct data));
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->value = v;
	
	if(head[s] == NULL){
		head[s] = tail[s] = newNode;
	}
	else{
		tail[s]->next = newNode;
		newNode->prev = tail[s];
		tail[s] = newNode;
	}
}


void popTail(int s){
	if(head[s] == NULL) return;
	
	if(head[s] == tail[s]){
		free(head[s]);
		head[s] = tail[s] = NULL;
	} else {
//		struct data *prev = tail[s]->prev;
		tail[s] = tail[s]->prev;
		free(tail[s]->next);
		tail[s]->next = NULL; 
	}
}

void popHead(int t){
	if(head[t] == NULL) return;
	
	if(head[t] == tail[t]){
		free(head[t]);
		head[t] = tail[t] = NULL;
	} else {
		head[t] = head[t]->next;
		free(head[t]->prev);
		head[t]->prev = NULL;
	}
}

void freeAll(int n){
	
	for(int i = 1; i <= n; i++){
		if(head[i] != NULL){
			while(head[i]->next != NULL){
				head[i] = head[i]->next; // 1
				free(head[i]->prev); 
				head[i]->prev = NULL; 
			}
			free(head[i]);
			head[i] = tail[i] = NULL;
		}
		
	}
}

int main(){
	
	int T = 0;
	int n = 0, q = 0;
	int op = 0;
	int s = 0, v = 0, t = 0;
	
	scanf("%d", &T);
	for(int a=0; a<T; a++){
		scanf("%d %d", &n, &q);
		
		for(int i=1; i<=n; i++){
			head[i] = tail[i] = NULL;
		}
		
		for(int b=0; b<q; b++){
			scanf("%d", &op);
			if(op == 1){
				scanf("%d %d", &s, &v);
				pushTail(s, v);
			}
			else if(op == 2){
				scanf("%d", &s);
				if(head[s] == NULL){
					printf("EMPTY\n");
				}
				else{
					printf("%d\n", tail[s]->value);
					popTail(s);
				}
			}
			else if(op == 3){
				scanf("%d %d", &s, &t);
				if(head[t] != NULL){
					if(head[s] == NULL){
						head[s] = head[t];
						tail[s] = tail[t];
					}
					else{
						tail[s]->next = head[t];
						head[t]->prev = tail[s];
						tail[s] = tail[t];
					}
					head[t] = tail[t] = NULL;
					
				}
				
//				while(head[t] != NULL){
//					pushTail(s, head[t]->value);
//					popHead(t);
//				}
			}
		}
		freeAll(n);
	}
	
	return 0;
}