#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
	char input;
	struct data *nextS;
	struct data *nextO;
};


void pushStack(struct data **localHeadS, char i){
/*
	// push Belakang
//	printf("%c\n", i);
	struct data *newNodeS = (struct data*)malloc(sizeof(struct data));
	newNodeS->nextS = NULL;
	newNodeS->input = i;
//	printf("%c\n", newNodeS->input);
	
	if(*localHeadS == NULL){
//		printf("aaa\n");
		*localHeadS = newNodeS;
	}
	else{
//		printf("bbb\n");
		struct data *currentLocationS = *localHeadS;
		while(currentLocationS->nextS != NULL){
			currentLocationS = currentLocationS->nextS;
		}
		currentLocationS->nextS = newNodeS;
//		currentLocationS->nextS = NULL;
	}
*/
	
	// push depan
	struct data *newNodeS = (struct data*)malloc(sizeof(struct data));
	newNodeS->nextS = NULL;
	newNodeS->input = i;
	
	if(*localHeadS == NULL){
		*localHeadS = newNodeS;
	}
	else{
		newNodeS->nextS = *localHeadS;
		*localHeadS = newNodeS;
	}
}

void popDpn(struct data **localHeadS){
	if((*localHeadS) == NULL) return;
	
	struct data *toBeDeleted = *localHeadS;
	*localHeadS = (*localHeadS)->nextS;
	
	free(toBeDeleted);
}


void pushOutput(struct data **localHeadO, char i){
	// push Belakang
//	printf("output\n");
	struct data *newNodeO = (struct data*)malloc(sizeof(struct data));
	newNodeO->nextO = NULL;
	newNodeO->input = i;
	
	if(*localHeadO == NULL){
		*localHeadO = newNodeO;
	}
	else{
		struct data *currentLocationO = *localHeadO;
		while(currentLocationO->nextO != NULL){
			currentLocationO = currentLocationO->nextO;
		}
		currentLocationO->nextO = newNodeO;
//		currentLocationO->nextO = NULL;
	}
}

void printOutput(struct data *localHeadO){
	struct data *currentLocationO = localHeadO;
	while(currentLocationO != NULL){
		printf("%c", currentLocationO->input);
		currentLocationO = currentLocationO->nextO;
//		printf("lalalla");
	}
	printf("\n");
}

void printStack(struct data *localHeadS){
	struct data *currentLocationS = localHeadS;
	while(currentLocationS != NULL){
		printf("%c", currentLocationS->input);
//		printf("%s", *currentLocationS);
		currentLocationS = currentLocationS->nextS;
//		printf("nesss");
	}
	printf("\n");
}

void popOutput(struct data **localHeadO){
	if((*localHeadO) == NULL) return;
	
	struct data *toBeDeleted = *localHeadO;
	*localHeadO = (*localHeadO)->nextO;
	
	free(toBeDeleted);
}

void freeAll(struct data **localHeadO){
	while((*localHeadO) != NULL){
		popOutput(localHeadO);
	}
}



int main(){
	struct data *headS = NULL;
	struct data *headO = NULL;
	
	int T;
	char input[406];
	scanf("%d", &T);
	getchar();
	for(int a=0; a<T; a++){
//		int b=0;
//		while(true){
//printf("input char\n");
			scanf("%[^\n]", &input); getchar();
			
			for(int b=0; b<strlen(input); b++){
				if(input[b] == '\n') break;
				if(input[b] == '(' || input[b] == ')' || input[b] == '^' || input[b] == '+' || input[b] == '-' || input[b] == '*' || input[b] == '/' || input[b] == '%'){
//					printf("masuk if\n");
					
					if(input[b] == ')'){
						while(headS != NULL){
							pushOutput(&headO, headS->input);
							popDpn(&headS);
							popDpn(&headS);
							break;
						}
					}
					else pushStack(&headS, input[b]);
//					printf("selesai if\n");
					
				}
				else{
					pushOutput(&headO, input[b]);
//					printf("Test2\n");
				}
				
			}
			
//		}
//		printf("hellow\n");
//		printf("Isi Stack : ");
//		printStack(headS);
//		printf("Isi Output : ");
		printOutput(headO);
		
//		printf("mau hapus\n");
		freeAll(&headO);
//		printf("hapus dongg\n");
		
//		printf("%s", input[a]);
//		printf("b= %d\n", b);
//		printf("strlen = %d\n", strlen(input[a]));
//		for(int c=0; c<strlen(input[a]); c++){
//			if(input[a][c] == '\n') break;
//			printf("%c\n", input[a][c]);
//		}
	
	}
	
	return 0;
}
//wish me luck :)