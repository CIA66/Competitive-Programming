#include<stdio.h>
#include<stdlib.h>

struct node{
	
	int key;
	int height;
	struct node *left, *right;
	
};

int max(int a, int b){
	if(a < b) return b;
	return a;
}

int getHeight(struct node *curNode){
	
	if(curNode == NULL) return 0;
	return curNode->height;
}

int getBfactor(struct node *curNode){
	if(curNode == NULL) return 0;
	return getHeight(curNode->left) - getHeight(curNode->right);
}

struct node *newNode(int newKey){
	
	struct node *nNode = (struct node*)malloc(sizeof(struct node));
	
	nNode->key = newKey;
	nNode->height = 1;
	
	nNode->left = NULL;
	nNode->right = NULL;
	
	return nNode;
}

struct node *rightRotate(struct node *y){
	
	struct node *x = y->left;
	struct node *B = x->right;
	
	x->right = y;
	y->left = B;
	
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	
	return x;
}

struct node *leftRotate(struct node *x){
	
	struct node *y = x->right;
	struct node *B = y->left;
	
	y->left = x;
	x->right = B;
	
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	
	return y;
}

struct node *reBalance(struct node *localRoot){
	
	localRoot->height = max(getHeight(localRoot->left), getHeight(localRoot->right)) + 1;
	
	int currentBalance = getBfactor(localRoot);
	
	if(currentBalance > 1 && getBfactor(localRoot->left) >= 0){
		return rightRotate(localRoot);
	}
	if(currentBalance > 1 && getBfactor(localRoot->left) < 0){
		localRoot->left = leftRotate(localRoot->left);
		return rightRotate(localRoot);
	}
	if(currentBalance < -1 && getBfactor(localRoot->right) <= 0){
		return leftRotate(localRoot);
	}
	if(currentBalance < -1 && getBfactor(localRoot->right) < 0){
		localRoot->right = rightRotate(localRoot->right);
		return leftRotate(localRoot);
	}
	
	return localRoot;
}

int count;

struct node *insertData(struct node *curNode, int newKey){
	
	if(curNode == NULL) return newNode(newKey);
	else if(newKey < curNode->key){
		curNode->left = insertData(curNode->left, newKey);
	}
	else if(newKey > curNode->key){
		curNode->right = insertData(curNode->right, newKey);
	}
	else{
		count++;
	}
	
	return reBalance(curNode);
}

struct node *freeAll(struct node *curNode){
	if(curNode == NULL) return NULL;
	
	curNode->left = freeAll(curNode->left);
	curNode->right = freeAll(curNode->right);
	free(curNode);
	
	return NULL;
}

int main(){
	
	int N = 0, M = 0;
	int jack = 0, jill = 0;
	
	struct node *root = NULL;
	
	while(1){
		
		scanf("%d %d", &N, &M);
		
		if(N == 0 && M == 0) break;
		
		for(int i=0; i<N; i++){
			scanf("%d", &jack);
			root = insertData(root, jack);
		}
		
		for(int i=0; i<N; i++){
			scanf("%d", &jill);
			root = insertData(root, jill);
		}
		
		printf("%d\n", count);
		
		count = 0;
		root = freeAll(root);
	}
	return 0;
}