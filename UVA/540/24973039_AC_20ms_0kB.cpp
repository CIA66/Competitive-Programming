#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
	int value;
	struct data *prev, *next;
};

void pushBack(struct data **localHead, struct data **localTail, int x){
	struct data *newNode = (struct data*)malloc(sizeof(struct data));
	newNode->value = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	if(*localHead == NULL){
		*localHead = *localTail = newNode;
	} else {
		(*localTail)->next = newNode;
		newNode->prev = *localTail;
		*localTail = newNode;
	}
}

void popHead(struct data **localHead, struct data **localTail){
	if(*localHead == NULL) return;
	
	if(*localHead == *localTail){
		free(*localHead);
		*localHead = *localTail = NULL;
	} else {
		*localHead = (*localHead)->next;
		free((*localHead)->prev);
		(*localHead)->prev = NULL;
	}
}

void popAll(struct data **localHead, struct data **localTail){
	if(*localHead == NULL) return;
	
	while(*localHead != NULL){
		popHead(localHead, localTail);
	}
}

int elementIniTimBerapa[1000001];

int main(){
	struct data *headTeam[1006], *tailTeam[1006];
	for(int i=0; i<1006; i++){
		headTeam[i] = tailTeam[i] = NULL;
	}
	
	int k = 1;
	int T = 0;
	while(1){
		scanf("%d", &T);
		if(T == 0){
			break;	
		}
		
		for(int a=0; a<T; a++){
			popAll(&headTeam[a], &tailTeam[a]);
			
			int sumElement = 0;
			scanf("%d", &sumElement);
			for(int b=0; b<sumElement; b++){
				int element = 0;
				scanf("%d", &element);
				elementIniTimBerapa[element] = a;
			}
		}
		
		
		printf("Scenario #%d\n", k);
		
		char command[10];
		strcpy(command, "");
		
		struct data *head = NULL, *tail = NULL;
		while(1){
			
			scanf("%s", command);
			if(strcmp(command, "STOP") == 0){
				break;
			} else if(strcmp(command, "ENQUEUE") == 0) {
				int num;
				scanf("%d", &num);
				
				int nomorTeam = elementIniTimBerapa[num];
				if(headTeam[nomorTeam] == NULL){
					pushBack(&head, &tail, nomorTeam);
				}
				
				pushBack(&headTeam[nomorTeam], &tailTeam[nomorTeam], num);
			} else if(strcmp(command, "DEQUEUE") == 0) {
//				printf("Masuk kokk\n");
				int nomorTeam = head->value;
//				printf("headTeam : %d\n", head->value);
				printf("%d\n", headTeam[nomorTeam]->value);
				popHead(&headTeam[nomorTeam], &tailTeam[nomorTeam]);
				
				if(headTeam[nomorTeam] == NULL){
					popHead(&head, &tail);
				}
			}
		}
		k++;
		puts("");
	}
	
	return 0;
}