#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Orang{
	int height;
	char nama[22];
	int num;
	struct Orang *left, *right;
};

int max(int a, int b){
	if(a < b) return b;
	return a;
}

int getHeight(struct Orang *currNode){
	if(currNode == NULL) return 0;
	return currNode->height;
}

int getBFactor(struct Orang *currNode){
	if(currNode == NULL) return 0;
	return getHeight(currNode->left) - getHeight(currNode->right);
}

struct Orang *newNode(char name[], int number){
	struct Orang *nNode = (struct Orang*)malloc(sizeof(struct Orang));
	
	nNode->height = 1;
	nNode->left = NULL;
	nNode->right = NULL;
	strcpy(nNode->nama, name);
	nNode->num = number;
	
	return nNode;
}

struct Orang *rightRotate(struct Orang *y){
	struct Orang *x = y->left;
	struct Orang *B = x->right;
	
	x->right = y;
	y->left = B;
	
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	
	return x;
}

struct Orang *leftRotate(struct Orang *x){
	struct Orang *y = x->right;
	struct Orang *B = y->left;
	
	y->left = x;
	x->right = B;
	
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	
	return y;
}

struct Orang *insertData(struct Orang *currentRoot, char newName[], int newNumber){
	if(currentRoot == NULL) return newNode(newName, newNumber);
	else if(strcmp(newName, currentRoot->nama) < 0){
		currentRoot->left = insertData(currentRoot->left, newName, newNumber);
	} else if(strcmp(newName, currentRoot->nama) > 0){
		currentRoot->right = insertData(currentRoot->right, newName, newNumber);
	} else {
		
	}
	
	currentRoot->height = max(getHeight(currentRoot->left), getHeight(currentRoot->right)) + 1;
	
	int bFactor = getBFactor(currentRoot);
	
	if(bFactor > 1 && strcmp(newName, currentRoot->left->nama) < 0){
		return rightRotate(currentRoot);
	}
	if(bFactor < -1 && strcmp(newName, currentRoot->right->nama) > 0){
		return leftRotate(currentRoot);
	}
	if(bFactor > 1 && strcmp(newName, currentRoot->left->nama) > 0){
		currentRoot->left = leftRotate(currentRoot->left);
		return rightRotate(currentRoot);
	}
	if(bFactor < -1 && strcmp(newName, currentRoot->right->nama) < 0){
		currentRoot->right = rightRotate(currentRoot->right);
		return leftRotate(currentRoot);
	}
	
	return currentRoot;
}
int isExist(struct Orang *currentRoot, char X[]){
	if(currentRoot == NULL) return -1;
	else if(strcmp(X, currentRoot->nama) < 0){
		return isExist(currentRoot->left, X);
	} else if(strcmp(X, currentRoot->nama) > 0){
		return isExist(currentRoot->right, X);
	} else {
		return currentRoot->num;
	}
}

struct Orang *freeAll(struct Orang *currentRoot){
	if(currentRoot == NULL) return NULL;
	currentRoot->left = freeAll(currentRoot->left);
	currentRoot->right = freeAll(currentRoot->right);
	free(currentRoot);
	return NULL;
}

#define MAXN 100000

int Parent[MAXN + 10];
int Group[MAXN + 10];

void makeSet(int n){
	for(int i=0; i<n; i++){
		Parent[i] = i;
		Group[i] = 1;
	}
}

int findParent(int x){
	if(Parent[x] == x) return x;
	return Parent[x] = findParent(Parent[x]);
}

void merge(int a, int b){
	Parent[findParent(a)] = findParent(b);
}

int isSameSet(int a, int b){
	return findParent(a) == findParent(b);
}

struct edge{
	int a, b;
	int cost;
};

struct edge arr[100006];

int main(){
	int T = 0, F = 0;
	char nama1[22], nama2[22];
	scanf("%d", &T);
	for(int a=0; a<T; a++){
		scanf("%d", &F);
		if(F*2 < 100000){
			makeSet(F*2);
		} else {
			makeSet(100000);
		}
		struct Orang *root = NULL;
		int number = 0;
		
		for(int i=0; i<F; i++){
			
			scanf("%s %s", nama1, nama2);
//			toLower(nama1); toLower(nama2);
			int temp = isExist(root, nama1);
//			printf("%s %s\n", nama1, nama2);
			if(temp == -1){
				root = insertData(root, nama1, number);
				arr[i].a = number;
				number++;
			} else {
				arr[i].a = temp;
			}
			
			temp = isExist(root, nama2);
//			printf("temp : %d\n", temp);
			if(temp == -1){
				root = insertData(root, nama2, number);
//				printf("test\n");
				arr[i].b = number;
				number++;
			} else {
				arr[i].b = temp;
			}
//			printf("%d %d\n", arr[i].a, arr[i].b);

			int sama = isSameSet(arr[i].a, arr[i].b);
			int left = 0, right = 0;
			left = findParent(arr[i].a);
			right = findParent(arr[i].b);
			
			if(sama == 0){
				
				if(Group[left] < Group[right]){
					Group[right] = Group[right] + Group[left];
					Parent[left] = right;
					printf("%d\n", Group[right]);
					
				} else {
					Group[left] = Group[left] + Group[right];
					Parent[right] = left;
					printf("%d\n", Group[left]);
				}
				
			} else {
				printf("%d\n", Group[left]);
			}
		}
		root = freeAll(root);
	}
	return 0;
}