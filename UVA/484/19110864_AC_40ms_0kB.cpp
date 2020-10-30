/*

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct condition{
	int num;
	int count;
	int urutan;
};

struct data{
	struct condition currCondition;
	struct data *next;
	struct data *prev;
};

void pushTail(struct data **localHead, struct data **localTail, struct condition currCond, int *countData){
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
	(*countData)++;
}

void popDepan(struct data **localHead, struct data **localTail, int *countData){
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
	(*countData)--;
}

int hash(const char *str, int base, int MOD) {
	int len = strlen(str);
	int ans = 0;
	for(int i=0; i<len; i++) {
		// ((str[i] - '0') + 1)
		// ini tuh konversi dari 0 .. 9 ke 1 .. 10
		ans =  ((( (ans%MOD)  + (((str[i] - '0') + 1)%MOD)  )%MOD) * (base%MOD) ) % MOD;
		//ans = (( (ans%MOD) * (base%MOD)) % MOD) + (((str[i]-'0') + 1) % MOD)
	}
	return ans;
}


int main(){
	
	struct data *head[40];
	struct data *tail[40];
	int countData[40];
	
	for(int a=0; a<40; a++){
		head[a] = tail[a] = NULL;
		countData[a] = 0;
	}
	
	int inputNum = 0;
	int count = 0;
	int urutan = 0;
	
	char space;
	while(scanf("%d%c", &inputNum, &space) != EOF){
//		getchar();
//		if(inputNum = '\n') break;
//		printf("%d\n", inputNum);

		count = 0;
		urutan = 0;
		
		char strInputNum[20];
		sprintf(strInputNum, "%d", inputNum);
		
		int idxHash = hash(strInputNum, 19, 47);
		
		int flag = 0;
//		printf("inputNum : %d\n", inputNum);
		struct data *curr = *head;
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
			s.urutan = urutan+1;
			pushTail(&head[idxHash], &tail[idxHash], s, countData);
		}
		if(space == '\n') break;
	}
//	printf("done\n");
	for(int i=0; i<40; i++){
		struct data *curr = head[i];		
		while(curr){
			if(curr->currCondition.urutan == urutan){
				printf("%d %d\n", curr->currCondition.num, curr->currCondition.count);
				urutan++;
			}
		}
	}
	
	return 0;
}

*/

// 	INI YANG AC

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