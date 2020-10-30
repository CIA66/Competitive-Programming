#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct node{
	long long int Key;
	int height;
	int size;
	
	struct node *left, *right;
};


struct node *newNode(long long int newKey){
	
	struct node *nNode = (struct node*)malloc(sizeof(struct node));
	
	nNode->Key = newKey;
	nNode->height = 1;
	nNode->size = 1;
	
	nNode->left = NULL;
	nNode->right = NULL;
	
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

struct node *reBalance(struct node *currentRoot){
	
	currentRoot->height = max(getHeight(currentRoot->left), getHeight(currentRoot->right)) + 1;
	
	currentRoot->size = getSize(currentRoot->left) + getSize(currentRoot->right) + 1;
	
	int currentBalance = getBFactor(currentRoot);
	
	if(currentBalance > 1 && getBFactor(currentRoot->left) >= 0){
		return rightRotate(currentRoot);
	}
	if(currentBalance > 1 && getBFactor(currentRoot->left) < 0){
		currentRoot->left = leftRotate(currentRoot->left);
		return rightRotate(currentRoot);
	}
	if(currentBalance < -1 && getBFactor(currentRoot->right) <= 0){
		return leftRotate(currentRoot);
	}
	if(currentBalance < -1 && getBFactor(currentRoot->right) > 0){
		currentRoot->right = rightRotate(currentRoot->right);
		return leftRotate(currentRoot);
	}
	
	return currentRoot;
	
}

long long int countData;

struct node *insertData(struct node *currentNode, long long int newKey){
	
	if(currentNode == NULL) {
		countData++;
		return newNode(newKey);
	}
	else if( newKey < currentNode->Key){
		currentNode->left = insertData(currentNode->left, newKey);
	}
	else if( newKey >= currentNode->Key){
		currentNode->right = insertData(currentNode->right, newKey);
	}
	else{
		countData++;
		return currentNode;
	}
	
	return reBalance(currentNode);
	
}

void inOrder(struct node *currentNode){
	if(currentNode == NULL) return;
	
	inOrder(currentNode->left);
//	printf(" %lld (%d) ", currentNode->Key, currentNode->count);
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

int found;

struct node *deleteData(struct node *currentNode, long long int toBeDeleted){
	
	if(currentNode == NULL) return NULL;
	else if( toBeDeleted < currentNode->Key){
		currentNode->left = deleteData(currentNode->left, toBeDeleted);
	}
	else if( toBeDeleted > currentNode->Key){
		currentNode->right = deleteData(currentNode->right, toBeDeleted);
	}
	else{
		
		found = 1;
		
//		if(currentNode->count > 1){
//			return currentNode;
//		}
//		else{
			
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
//		}
	}
	
	if(currentNode == NULL) return NULL;
	
	return reBalance(currentNode);
	
}

long long int Kth(struct node *currentNode, long long int k){
	
	if(currentNode == NULL){
		return 0;
	}
	else if(k == (getSize(currentNode->left) + 1) ){
		return currentNode->Key;
	}
	else if(k < (getSize(currentNode->left) + 1) ){
		return Kth(currentNode->left, k);
	}
	else if(k > (getSize(currentNode->left) + 1) ){
		return Kth(currentNode->right, (k - (getSize(currentNode->left) + 1) ) );
	}
	
	return 0;
}

void Median(struct node *currentRoot){
	
	int temp = countData % 2;
	if(temp == 1){
		
		printf("%lld\n", Kth(currentRoot, (countData / 2 + 1) ));

	}
	else{
		
		long long int num1 = Kth(currentRoot, countData / 2);
		long long int num2 = Kth(currentRoot, (countData / 2) + 1);
		
//		printf("Num1 : %lld\n", num1);
//		printf("Num2 : %lld\n", num2);

		long long int sum = num1 + num2;
		
		if(sum % 2 == 0){
			printf("%lld\n", sum / 2);
		}
		else{
			printf("%.1lf\n", sum / 2.0);
		}
		
	}
}

int main(){
	
	int N = 0;
	char op[6]; long long int x = 0;
	struct node *root = NULL;
	countData = 0;
	
	scanf("%d", &N);
	
	for(int a=0; a<N; a++){
		
		found = 0;
		
		scanf("%s %lld", op, &x);
			
		if(strcmp(op, "a") == 0){
			root = insertData(root, x);
			found = 1;
		}
		else if(strcmp(op, "r") == 0){
			root = deleteData(root, x);
			if(found == 1){
				countData--;
			}
		}
		
//		printf("CountData : %lld\n", countData);
		
		if(found == 0 || root == NULL){
			printf("Wrong!\n");
		}
		else{
			Median(root);
		}
		
//		printf("List : "); inOrder(root); puts("");
		
	}
	return 0;
}