
#include <stdio.h>
#include <stdlib.h>


struct data{
    int value;
    struct data *prev, *next;
};

void pushBack(struct data **localHead, struct data **localTail, int x){
    struct data *nNode = (struct data*)malloc(sizeof(struct data));
    nNode->value = x;
    nNode->next = NULL;
    nNode->prev = NULL;
    
    if(*localHead == NULL) *localHead = *localTail = nNode;
    else {
        nNode->prev = *localTail;
        (*localTail)->next = nNode;
        *localTail = nNode;
    }
    
}

void pushFront(struct data **localHead, struct data **localTail, int x){
    
    struct data *nNode  = (struct data*)malloc(sizeof(struct data));
    nNode->value = x;
    nNode->next = NULL;
    nNode->prev = NULL;
    
    if(*localHead == NULL) *localHead = *localTail = nNode;
    else{
        nNode->next = *localHead;
        (*localHead)->prev = nNode;
        *localHead = nNode;
    }
    
}


void popTail(struct data **localHead, struct data **localTail){
    
    if(*localHead == NULL) return;
    
    if(*localHead == *localTail){
        free(*localHead);
        *localHead = *localTail = NULL;
    }
    else{
        struct data *toBeDeleted = *localTail;
        *localTail = toBeDeleted->prev;
        (*localTail)->next = NULL;
        free(toBeDeleted);
    }
}

void popHead(struct data **localHead, struct data **localTail){
    if(*localHead == NULL) return;
    
    if(*localHead == *localTail){
        free(*localHead);
        *localHead = *localTail = NULL;
    }
    else{
        struct data *toBeDeleted = *localHead;
        *localHead = toBeDeleted->next;
        (*localHead)->prev = NULL;
        free(toBeDeleted);
    }
    
}

void pushPQ(struct data **localHead, struct data **localTail, int  x){
    
    struct data *nNode = (struct data*)malloc(sizeof(struct data));
    nNode->value = x;
    nNode->next = NULL;
    nNode->prev = NULL;
    
    if(*localHead == NULL) *localHead = *localTail = nNode;
    else if((*localTail)->value <= x)
        pushBack(localHead, localTail, x);
    else if((*localHead)->value >= x)
        pushFront(localHead, localTail, x);
    else{
        struct data *currData = *localHead;
        while(currData != NULL){
            if(currData->value >= x) break;
            currData = currData->next;
        }
        nNode->next = currData;
        nNode->prev = currData->prev;
        currData->prev->next = nNode;
        currData->prev = nNode;
    }
}

void freeAll(struct data **localHead, struct data **localTail){
    if(*localHead == NULL) return;
    
    while(*localHead != NULL){
        popHead(localHead, localTail);
    }
}

void printAll(struct data *localHead){
    if(localHead == NULL) return;
    
    struct data *currData = localHead;
    while(currData->next != NULL){
        printf("%d ", currData->value);
        currData = currData->next;
    }
    printf("%d\n", currData->value);
}


int main()
{
    
    
    int N;
    while(scanf("%d", &N) != EOF){
        
        struct data *headStack = NULL, *tailStack = NULL;
        struct data *headQueue = NULL, *tailQueue = NULL;
        struct data *headPQ = NULL, *tailPQ = NULL;
        
        int cm, x;
        int validStack = 1, validQueue = 1, validPQ = 1;
        
        for(int i = 0; i < N; i++){
            scanf("%d %d", &cm, &x);
            
            if(cm == 1){
                pushBack(&headStack, &tailStack, x);
                pushBack(&headQueue, &tailQueue, x);
                pushPQ(&headPQ, &tailPQ, x);
            }
            else if(cm == 2){
                if(headStack == NULL || tailStack->value != x)
                    validStack = 0;
                else popTail(&headStack, &tailStack);
                
                if(headQueue == NULL || headQueue->value != x)
                    validQueue = 0;
                else popHead(&headQueue, &tailQueue);
                
                if(headPQ == NULL || tailPQ->value != x)
                    validPQ = 0;
                else popTail(&headPQ, &tailPQ);
            }
        }
        
        if(!validStack && !validQueue && !validPQ) printf("impossible\n");
        else if(validStack && !validQueue && !validPQ) printf("stack\n");
        else if(!validStack && validQueue && !validPQ) printf("queue\n");
        else if(!validStack && !validQueue && validPQ) printf("priority queue\n");
        else printf("not sure\n");
        
        freeAll(&headStack, &tailStack);
        freeAll(&headQueue, &tailQueue);
        freeAll(&headPQ, &tailPQ);
    }
    return 0;
}
