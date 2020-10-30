#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct data{
	long long int disc;
	int height;
	struct data *left, *right;
};

struct data *newNode(long long int newKey){
	struct data *nNode = (struct data*)malloc(sizeof(struct data));
	nNode->height = 1;
	nNode->disc = newKey;
	nNode->left = NULL;
	nNode->right = NULL;
	return nNode;
}

long long int max(long long int a, long long int b){
	if(a > b) return a;
	return b;
}

long long int getHeight(struct data *currentRoot){
	if(currentRoot == NULL) return 0;
	return currentRoot->height;
}

long long int getBFactor(struct data *currentRoot){
	if(currentRoot == NULL) return 0;
	return getHeight(currentRoot->left) - getHeight(currentRoot->right);
}

struct data *rightRotate(struct data *y){
	struct data *x = y->left;
	struct data *B = x->right;
	
	x->right = y;
	y->left = B;
	
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	
	return x;
}

struct data *leftRotate(struct data *x){
	struct data *y = x->right;
	struct data *B = y->left;
	
	y->left = x;
	x->right = B;
	
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	
	return y;
}

struct data *rebalance(struct data *currentRoot){
	currentRoot->height = max(getHeight(currentRoot->left), getHeight(currentRoot->right)) + 1;
	int bFactor = getBFactor(currentRoot);
	
	if(bFactor > 1){
		if(getBFactor(currentRoot->left) < 0){
			currentRoot->left = leftRotate(currentRoot->left);
		}
		return rightRotate(currentRoot);
	} else if(bFactor < -1){
		if(getBFactor(currentRoot->right) > 0){
			currentRoot->right = rightRotate(currentRoot->right);
		}
		return leftRotate(currentRoot);
	} else {
		
	}
	return currentRoot;
}


long long int count;
struct data *insertData(struct data *currentRoot, long long int newKey){
	if(currentRoot == NULL){
		return newNode(newKey);
	}
	if(newKey < currentRoot->disc){
		currentRoot->left = insertData(currentRoot->left, newKey);
	} else if(newKey > currentRoot->disc){
		currentRoot->right = insertData(currentRoot->right, newKey);
	} else {
		count++;
	}
	
	return rebalance(currentRoot);
}


struct data *freeAll(struct data *currentRoot){
	if(currentRoot == NULL) return NULL;
	currentRoot->left = freeAll(currentRoot->left);
	currentRoot->right = freeAll(currentRoot->right);
	free(currentRoot);
	return NULL;
}

int main(){
	long long int N = 0, M = 0;
	while(1){
		scanf("%lld %lld", &N, &M);
		if(N == 0 && M == 0) break;
		long long int jack = 0, jill = 0;
		struct data *root = NULL;
		for(int a=0; a<N; a++){
			scanf("%lld", &jack);
			root = insertData(root, jack);
		}
		count = 0;
		for(int b=0; b<M; b++){
			scanf("%lld", &jill);
			root = insertData(root, jill);
		}
		printf("%lld\n", count);
		root = freeAll(root);
	}
	
	return 0;
}
