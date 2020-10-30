#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
	char kata[60];
	int height;
	struct data *left, *right;
};

struct data *newNode(char newKey[]){
	struct data *newNode = (struct data*)malloc(sizeof(struct data));
	strcpy(newNode->kata, newKey);
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->height = 1;
	
	return newNode;
}

char toLower(char x){
	if('A' <= x && x <= 'Z') return x-'A'+'a';
	return x;
}

int max(int a, int b){
	if(a < b) return b;
	return a;
}

int getHeight(struct data *curNode){
	if(curNode == NULL) return 0;
	return curNode->height;
}

int getBFactor(struct data *curNode){
	if(curNode == NULL) return 0;
	return getHeight(curNode->left) - getHeight(curNode->right);
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
struct data *insertData(struct data *currentRoot, char newWord[]){
	if(currentRoot == NULL) return newNode(newWord);
	
	else if(strcmp(currentRoot->kata, newWord) < 0){
		currentRoot->right = insertData(currentRoot->right, newWord);
	} 
	else if(strcmp(currentRoot->kata, newWord) > 0){
		currentRoot->left = insertData(currentRoot->left, newWord);
	} else {
		
	}
	
	currentRoot->height = max(getHeight(currentRoot->left), getHeight(currentRoot->right)) + 1;
	int bFactor = getBFactor(currentRoot);
	
	if(bFactor > 1 && strcmp(newWord, currentRoot->left->kata) < 0){
		return rightRotate(currentRoot);
	}
	if(bFactor < -1 && strcmp(newWord, currentRoot->right->kata) > 0){
		return leftRotate(currentRoot);
	}
	if(bFactor > 1 && strcmp(newWord, currentRoot->left->kata) > 0){
		currentRoot->left = leftRotate(currentRoot->left);
		return rightRotate(currentRoot);
	}
	if(bFactor < -1 && strcmp(newWord, currentRoot->right->kata) < 0){
		currentRoot->right = rightRotate(currentRoot->right);
		return leftRotate(currentRoot);
	}
	return currentRoot;
}

void inOrder(struct data *currentRoot){
	if(currentRoot == NULL) return;
	
	inOrder(currentRoot->left);
	printf("%s\n", currentRoot->kata);
	inOrder(currentRoot->right);
}

int main(){
	struct data *root = NULL;
	
	char kata[60];
	strcpy(kata, "");
	
	while(scanf("%s", &kata) != EOF){
		int t = 0;
		int len = strlen(kata);
//		printf("len : %d\n", len);
		while(t < len){
			char temp[60];
			strcpy(temp, "");
			int b = 0;
			while(('A' <= kata[t] && kata[t] <= 'Z') || ('a' <= kata[t] && kata[t] <= 'z')){
				temp[b] = toLower(kata[t]);
				b++, t++;
			}
			temp[b] = '\0';
			int lenTemp = strlen(temp);
			if(lenTemp != 0) root = insertData(root, temp);
			t++;
		}
	}
	
	inOrder(root);
	
	return 0;
}