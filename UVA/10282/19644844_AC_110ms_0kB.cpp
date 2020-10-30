#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Data{
	char english[16];
	char foreign[16];
};

struct Node{
	int height;
	struct Data currData;
	struct Node *left, *right;
};


int max(int a, int b) {
	if (a < b) return b;
	return a;
}

int getHeight(struct Node *curNode) {
	if (curNode == NULL) return 0;
	return curNode->height;
}


int getBalFactor(struct Node *curNode) {
	if (curNode == NULL) return 0;
	return getHeight(curNode->left)
				- getHeight(curNode->right);
	
}

struct Node *newNode(struct Node *currentRoot, struct Data s){
	struct Node *nNode = (struct Node*)malloc(sizeof(struct Node));
	nNode->currData = s;
	nNode->left = NULL;
	nNode->right = NULL;
	nNode->height = 1;
	
	return nNode;
};

struct Node *rightRotate(struct Node *y) {
	struct Node *x = y->left;
	struct Node *B = x->right;
	
	// rotate
	x->right = y;
	y->left = B;
	
	y->height = max(getHeight(y->left),
						getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left),
						getHeight(x->right)) + 1;
	return x;
}

struct Node *leftRotate(struct Node *x) {
	struct Node *y = x->right;
	struct Node *B = y->left;
	
	// rotate
	y->left = x;
	x->right = B;
	
	x->height = max(getHeight(x->left),
						getHeight(x->right)) + 1;
						
	y->height = max(getHeight(y->left),
						getHeight(y->right)) + 1;
						
	return y;
}


struct Node *insertData(struct Node *currentRoot, struct Data X){
	if(currentRoot == NULL) return newNode(currentRoot, X);
	else if(strcmp(X.foreign, currentRoot->currData.foreign) < 0){
		currentRoot->left = insertData(currentRoot->left, X);
	}
	else if(strcmp(X.foreign, currentRoot->currData.foreign) > 0){
		currentRoot->right = insertData(currentRoot->right, X);
	}
	else{
		
	}
	
	currentRoot->height = max(getHeight(currentRoot->left), getHeight(currentRoot->right)) + 1;
								
	int bfactor = getBalFactor(currentRoot);
	
	if (bfactor > 1 && strcmp(X.foreign, currentRoot->left->currData.foreign) < 0) {
		return rightRotate(currentRoot);
	}
	if (bfactor < -1 && strcmp(X.foreign, currentRoot->right->currData.foreign) > 0) {
		return leftRotate(currentRoot);
	}
	if (bfactor > 1 && strcmp(X.foreign, currentRoot->left->currData.foreign) > 0) {
		currentRoot->left = leftRotate(currentRoot->left);
		return rightRotate(currentRoot);
	}
	if (bfactor < -1 && strcmp(X.foreign, currentRoot->right->currData.foreign) < 0) {
		currentRoot->right = rightRotate(currentRoot->right);
		return leftRotate(currentRoot);
	}
	return currentRoot;
	
}

void inOrder(struct Node *currentRoot){
	if(currentRoot == NULL) return;
	inOrder(currentRoot->left);
	printf("%s %s\n", currentRoot->currData.english, currentRoot->currData.foreign);
	inOrder(currentRoot->right);
}

int isExist(struct Node *currentRoot, const char *X){
	if(currentRoot == NULL) return 0;
	else if(strcmp(X, currentRoot->currData.foreign) < 0){
		return isExist(currentRoot->left, X);
	}
	else if(strcmp(X, currentRoot->currData.foreign) > 0){
		return isExist(currentRoot->right, X);
	}
	else{
		return 1;
	}
}

char *theEnglish(struct Node *currentRoot, const char *X){
	if(currentRoot == NULL) return NULL;
	else if(strcmp(X, currentRoot->currData.foreign) < 0){
		return theEnglish(currentRoot->left, X);
	}
	else if(strcmp(X, currentRoot->currData.foreign) > 0){
		return theEnglish(currentRoot->right, X);
	}
	else{
		return currentRoot->currData.english;
	}
}


struct Node *freeAll(struct Node *currentRoot) {
	if (currentRoot == NULL) return NULL;
	currentRoot->left = freeAll(currentRoot->left);
	currentRoot->right = freeAll(currentRoot->right);
	free(currentRoot);
	return NULL;
}

int main(){
	char english[16];
	char foreign[16];
	char str[36];
	struct Node *root = NULL;
	while(gets(str)){
		strcpy(english, "");
		strcpy(foreign, "");
		int len = strlen(str);
		if(len == 0){
//			getchar();
			break;
		}
		int first = 1;
		int a = 0, b = 0, c = 0;
		for(a=0; a<len; a++){
			if(str[a] == ' ') first = 0;
			else if(first == 1){
				english[c] = str[a];
				c++;
			}
			else if(first == 0){
				foreign[b] = str[a];
				b++;	
			}
		}
		english[c] = '\0';
		foreign[b] = '\0';
//		printf("%s %s\n", english, foreign);
		struct Data s;
		strcpy(s.english, english);
		strcpy(s.foreign, foreign);
		root = insertData(root, s);
	}
//	inOrder(root);
	
	char eng[16];
	while(gets(str)){
		int eh = -1;
		strcpy(eng, "");
		eh = isExist(root, str);
		if(eh == 1){
//			sscanf(eng, "%s", theEnglish(root, str));
			strcpy(eng, theEnglish(root, str));
			printf("%s\n", eng);
		} else if(eh == 0){
			printf("eh\n");
		}
	}
	root = freeAll(root);
	
	return 0;
}