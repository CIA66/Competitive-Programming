#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct condition{
	int num;
	int count;
};

struct data{
	struct condition currCondition;
	struct data *next;
	struct data *prev;
};

void pushTail(struct data **localHead, struct data **localTail, struct condition currCond){
	struct data *newNode = (struct data*)malloc(sizeof(struct data));
	
	newNode->currCondition = currCond;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	if(*localHead == NULL){
		*localHead = newNode;
		*localTail = newNode;
	}
	else{
		(*localTail)->next = newNode;
		newNode->prev = *localTail;
		*localTail = newNode;
	}
}

void popDepan(struct data **localHead, struct data **localTail){
	if(*localHead == NULL) return;
	
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

int main(){
	
	struct data *head = NULL;
	struct data *tail = NULL;
	
	int inputNum = 0;
	int jumlahNode = 0;
	
	char space;
	while(scanf("%d%c", &inputNum, &space) != EOF){
//		printf("%d\n", inputNum);
		

		int flag = 0;
		int count = 0;
		struct data *curr = head;
//		printf("inputNum : %d\n", inputNum);
		while(curr){
//			printf("Cek inputNum udh ada atau blm, ini curr : %d\n", curr->currCondition.num);
			if(curr->currCondition.num == inputNum){
//				printf("%d sudah ada sebelumnya di list\n", inputNum);
				curr->currCondition.count++;
//				printf("inputNum %d counternya jadi %d\n", curr->currCondition.num, curr->currCondition.count);
				flag = 1;
				break;
			}
			curr = curr->next;
		}
		
		if(flag == 0){
			struct condition s;
			s.num = inputNum;
			s.count = count+1;
			pushTail(&head, &tail, s);
			jumlahNode++;
		}
		if(space == '\n') break;
	}
		
	
	for(int i=0; i<jumlahNode; i++){
		printf("%d %d\n", head->currCondition.num, head->currCondition.count);
		popDepan(&head, &tail);
	}
	
	return 0;
}