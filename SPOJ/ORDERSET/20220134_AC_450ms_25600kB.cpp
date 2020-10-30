// INI YANG AC :)

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
	long long int Key;
	int height;
	struct node *left, *right;
	int size;
};

struct node *newNode(long long int newKey){
	struct node *nNode = (struct node*)malloc(sizeof(struct node));
	nNode->Key = newKey;
	nNode->height = 1;
	
	nNode->left = NULL;
	nNode->right = NULL;
	
	nNode->size = 1;
	
	return nNode;
}

int max(int a, int b){
	if(a < b) return b;
	return a;
}

int getHeight(struct node *curNode){
	if(curNode == NULL) return 0;
	return curNode->height;
}

int getBFactor(struct node *curNode){
	if(curNode == NULL) return 0;
	return getHeight(curNode->left) - getHeight(curNode->right);
}

int getSize(struct node *curNode){
	if(curNode == NULL) return 0;
	return curNode->size;
}

struct node *rightRotate(struct node *y){
	struct node *x = y->left;
	struct node *B = x->right;
	
	x->right = y;
	y->left = B;
	
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	y->size = getSize(y->left) + getSize(y->right) + 1;
	
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	x->size = getSize(x->left) + getSize(x->right) + 1;
	
	return x;
}

struct node *leftRotate(struct node *x){
	struct node *y = x->right;
	struct node *B = y->left;
	
	y->left = x;
	x->right = B;
	
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	x->size = getSize(x->left) + getSize(x->right) + 1;
	
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	y->size = getSize(y->left) + getSize(y->right) + 1;
	
	return y;
}

struct node *rebalance(struct node *localRoot){
	
	localRoot->height = max(getHeight(localRoot->left), getHeight(localRoot->right)) + 1;
	
	localRoot->size = getSize(localRoot->left) + getSize(localRoot->right) + 1;
	
	int currentBalance = getBFactor(localRoot);
	
	if(currentBalance > 1 && getBFactor(localRoot->left) >= 0){
		return rightRotate(localRoot);
	}
	if(currentBalance > 1 && getBFactor(localRoot->left) < 0){
		localRoot->left = leftRotate(localRoot->left);
		return rightRotate(localRoot);
	}
	if(currentBalance < -1 && getBFactor(localRoot->right) <= 0){
		return leftRotate(localRoot);
	}
	if(currentBalance < -1 && getBFactor(localRoot->right) > 0){
		localRoot->right = rightRotate(localRoot->right);
		return leftRotate(localRoot);
	}
	
	return localRoot;
}

struct node *insertData(struct node *currentNode, long long int newKey){
	
	if(currentNode == NULL) return newNode(newKey);
	else if(newKey > currentNode->Key){
		currentNode->right = insertData(currentNode->right, newKey);
	}
	else if(newKey < currentNode->Key){
		currentNode->left = insertData(currentNode->left, newKey);
	}
	else {
		
	}
	
	return rebalance(currentNode);
}

void inOrder(struct node *currentNode){
	if(currentNode == NULL) return;
	
	inOrder(currentNode->left);
	printf(" %lld ", currentNode->Key);
	inOrder(currentNode->right);
}

struct node *successor(struct node *currentNode){
	
	currentNode = currentNode->right;
	
	while(currentNode->left != NULL){
		currentNode = currentNode->left;
	}
	
	return currentNode;
}

struct node *deleteData(struct node *currentNode, long long int toBeDeleted){
	
	if(currentNode == NULL) return NULL;
	else if(toBeDeleted > currentNode->Key){
		currentNode->right = deleteData(currentNode->right, toBeDeleted);
	}
	else if(toBeDeleted < currentNode->Key){
		currentNode->left = deleteData(currentNode->left, toBeDeleted);
	}
	else {
		
		if(currentNode->left == NULL && currentNode->right == NULL){
			free(currentNode);
			return NULL;
		}
		else if(currentNode->left == NULL && currentNode->right != NULL){
			struct node *rChild = currentNode->right;
			free(currentNode);
			return rChild;
		}
		else if(currentNode->left != NULL && currentNode->right == NULL){
			struct node *lChild = currentNode->left;
			free(currentNode);
			return lChild;
		}
		else{
			
			struct node *suksesor = successor(currentNode);
			currentNode->Key = suksesor->Key;
			currentNode->right = deleteData(currentNode->right, suksesor->Key); 
			
		}
	}
	
	if(currentNode == NULL) return NULL;
	
	return rebalance(currentNode);
	
}


int Kth(struct node *currentNode, long long int k){
	
	if(currentNode == NULL){
		return 0;
	}
	else if(k == (getSize(currentNode->left) + 1) ){
		return currentNode->Key;
	}
	else if(k < (getSize(currentNode->left) + 1) ){
		return Kth(currentNode->left, k);
	}
	else if(k > (getSize(currentNode->left) + 1) ) {
		return Kth(currentNode->right, (k - (getSize(currentNode->left) + 1) ) );
	}
}


int Count(struct node *currentNode, long long int x){
	
	if(currentNode == NULL){
		return 0;
	}
	else if(x < currentNode->Key){
		return Count(currentNode->left, x);
	}
	else if(x > currentNode->Key){
		return getSize(currentNode->left) + 1 + Count(currentNode->right, x);
	}
	else{
		return getSize(currentNode->left);
	}
	
}

struct node *freeAll(struct node *curNode){
	
	if(curNode == NULL) return NULL;
	
	curNode->left = freeAll(curNode->left);
	curNode->right = freeAll(curNode->right);
	free(curNode);
	
	return curNode;
}

int main(){
	
	long long int Q = 0, a = 0;
	char operation[6]; long long int parameter = 0;
	struct node *root = NULL;
	
	scanf("%lld", &Q);
	
	for(a = 0; a < Q; a++){
		
		scanf("%s", operation);
		scanf("%lld", &parameter);
		
		if(strcmp(operation, "I") == 0){
			root = insertData(root, parameter);
		}
		else if(strcmp(operation, "D") == 0){
			root = deleteData(root, parameter);
		}
		else if(strcmp(operation, "K") == 0){
			int kth = Kth(root, parameter);
			if(kth == 0){
				printf("invalid\n");
			}
			else{
				printf("%d\n", kth);
			}
		}
		else if(strcmp(operation, "C") == 0){
			printf("%d\n", Count(root, parameter));
		}
		
//		printf("List : "); inOrder(root); puts("");
	}
	
	root = freeAll(root);
	
	return 0;
}  