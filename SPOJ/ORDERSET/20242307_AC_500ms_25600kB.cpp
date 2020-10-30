#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node{
	long long int Key;
	int height;
	int size;
	
	struct node *left, *right;
};

int max(int a, int b){
	if(a < b) return b;
	return a; 
}

int getHeight(struct node *curNode){
	if(curNode == NULL) return 0;
	return curNode->size;
}

int getSize(struct node *curNode){
	if(curNode == NULL) return 0;
	return curNode->size;
}

int getBfactor(struct node *curNode){
	if(curNode == NULL) return 0;
	return getHeight(curNode->left) - getHeight(curNode->right); 
}

struct node *rightRotate(struct node *y){
	
	struct node *x = y->left;
	struct node *B = x->right;
	
	x->right = y;
	y->left = B;
	
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	
	y->size = getSize(y->left) + getSize(y->right) + 1;
	x->size = getSize(x->left) + getSize(x->right) + 1;
	
	return x;
}

struct node *leftRotate(struct node *x){
	
	struct node *y = x->right;
	struct node *B = y->left;
	
	y->left = x;
	x->right = B;
	
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	
	x->size = getSize(x->left) + getSize(x->right) + 1;
	y->size = getSize(y->left) + getSize(y->right) + 1;
	
	return y;
}

struct node *newData(long long int newKey){
	
	struct node *nNode = (struct node*)malloc(sizeof(struct node));
	
	nNode->Key = newKey;
	nNode->size = 1;
	nNode->height = 1;
	
	nNode->left = NULL;
	nNode->right = NULL;
	
	return nNode;
}

struct node *reBalance(struct node *localRoot){
	
	localRoot->height = max(getHeight(localRoot->left), getHeight(localRoot->right)) + 1;
	
	localRoot->size = getSize(localRoot->left) + getSize(localRoot->right) + 1;
	
	int currentBalance = getBfactor(localRoot);
	
	if(currentBalance < -1 && getBfactor(localRoot->right) <= 0){
		return leftRotate(localRoot);
	}
	if(currentBalance < -1 && getBfactor(localRoot->right) > 0){
		localRoot->right = rightRotate(localRoot->right);
		return leftRotate(localRoot);
	}
	if(currentBalance > 1 && getBfactor(localRoot->left) >= 0){
		return rightRotate(localRoot);
	}
	if(currentBalance > 1 && getBfactor(localRoot->left) < 0){
		localRoot->left = leftRotate(localRoot->left);
		return rightRotate(localRoot);
	}
	
	return localRoot;
}

struct node *insertData(struct node *curNode, long long int newKey){
	
	if(curNode == NULL) return newData(newKey);
	else if(newKey < curNode->Key){
		curNode->left = insertData(curNode->left, newKey);
	}
	else if(newKey > curNode->Key){
		curNode->right = insertData(curNode->right, newKey);
	}
	else{
		
	}
	
	return reBalance(curNode);
}

struct node *successor(struct node *curNode){
	
	curNode = curNode->right;
	
	while(curNode->left != NULL){
		curNode = curNode->left;
	}
	
	return curNode;
}

struct node *deleteData(struct node *curNode, long long int toBeDeleted){
	
	if(curNode == NULL) return NULL;
	else if(toBeDeleted < curNode->Key){
		curNode->left = deleteData(curNode->left, toBeDeleted);
	}
	else if(toBeDeleted > curNode->Key){
		curNode->right = deleteData(curNode->right, toBeDeleted);
	}
	else {
		
		if(curNode->left == NULL && curNode->right == NULL){
			free(curNode);
			return NULL;
		}
		else if(curNode->left == NULL && curNode->right != NULL){
			struct node *rChild = curNode->right;
			free(curNode);
			return rChild;
		}
		else if(curNode->left != NULL && curNode->right == NULL){
			struct node *lChild = curNode->left;
			free(curNode);
			return lChild;
		} 
		else{
			
			struct node *suksesor = successor(curNode);
			curNode->Key = suksesor->Key;
			curNode->right = deleteData(curNode->right, suksesor->Key);
			
		}
	}
	
	if(curNode == NULL) return NULL;
	
	return reBalance(curNode);
	
}

long long int Kth(struct node *curNode, long long int k){
	
	if(curNode == NULL) return 0;
	else if( k == (getSize(curNode->left) + 1) ){
		return curNode->Key;
	}
	else if( k < (getSize(curNode->left) + 1) ){
		return Kth(curNode->left, k);
	}
	else if( k > (getSize(curNode->left) + 1) ){
		return Kth(curNode->right, (k - (getSize(curNode->left) + 1) ) );
	}
	
}

int Count(struct node *curNode, long long int x){
	
	if(curNode == NULL) return 0;
	else if(x < curNode->Key){
		return Count(curNode->left, x);
	}
	else if(x > curNode->Key){
		return getSize(curNode->left) + 1 + Count(curNode->right, x);
	}
	else{
		return getSize(curNode->left);
	}
	
}

struct node *freeAll(struct node *curNode){
	
	if(curNode == NULL) return NULL;
	
	curNode->left = freeAll(curNode->left);
	curNode->right = freeAll(curNode->right);
	free(curNode);
	
	return NULL;
}

void inOrder(struct node *curNode){
	
	if(curNode == NULL) return;
	
	inOrder(curNode->left);
	printf(" %lld ", curNode->Key);
	inOrder(curNode->right);
}

int main(){
	
	int Q = 0;
	
	struct node *root = NULL;
	char op[6]; long long int parameter = 0;
	
	scanf("%d", &Q);
	
	for(int a=0; a<Q; a++){
		
		scanf("%s %lld", op, &parameter);
		
		if(strcmp(op, "I") == 0){
			root = insertData(root, parameter);
		}
		else if(strcmp(op, "D") == 0){
			root = deleteData(root, parameter);
		}
		else if(strcmp(op, "K") == 0){
			
			long long int kth = Kth(root, parameter);
			
			if(kth == 0){
				printf("invalid\n");
			}
			else{
				printf("%lld\n", kth);
			}
		}
		else if(strcmp(op, "C") == 0){
			
			printf("%d\n", Count(root, parameter));
		}
		
//		printf("List : "); inOrder(root); puts("");
		
	}
	
	root = freeAll(root);
	
	return 0;
}
