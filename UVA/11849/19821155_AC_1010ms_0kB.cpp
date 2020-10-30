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

long long int max(int a, int b) {
	return (a < b) ? b : a;
}

long long int getHeight(struct data *localRoot) {
	if (localRoot == NULL) return 0;
	return localRoot->height;
}

// get Balance Factor
long long int getBF(struct data *localRoot) {
	if (localRoot == NULL) return 0;
	return getHeight(localRoot->left)
				- getHeight(localRoot->right);
}


struct data *rightRotate(struct data *y) {
	struct data *x = y->left;
	struct data *B = x->right;
	// rotate
	x->right = y;
	y->left = B;
	
	y->height = max(getHeight(y->left),
					getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left),
					getHeight(x->right)) + 1;
					
	return x;
}

struct data *leftRotate(struct data *x) {
	struct data *y = x->right;
	struct data *B = y->left;
	
	// rotate
	y->left = x;
	x->right = B;
	
	x->height = max(getHeight(x->left),
					getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left),
					getHeight(y->right)) + 1;
					
	return y;
}

struct data *rebalance(struct data *localRoot) {
	
	localRoot->height = max(getHeight(localRoot->left),
								getHeight(localRoot->right)) + 1;
	long long int bfactor = getBF(localRoot);

	if (bfactor > 1) {
		if (getBF(localRoot->left) < 0) {
			localRoot->left = leftRotate(localRoot->left);
		}
		return rightRotate(localRoot);
	} else if (bfactor < -1) {
		if (getBF(localRoot->right) > 0) {
			localRoot->right = rightRotate(localRoot->right);
		}
		return leftRotate(localRoot);
	} else {
		// tree balance! yeay!
	}
	return localRoot;

}

long long int count;
struct data *insertAVL(struct data *localRoot,
								int newKEY) {
	if (localRoot == NULL) return newNode(newKEY);
	if (localRoot->disc > newKEY) {
		localRoot->left = insertAVL(localRoot->left,
										newKEY);
	} else if (localRoot->disc < newKEY) {
		localRoot->right = insertAVL(localRoot->right,
										newKEY);
	} else {
		count++;
		// ini sama... ignore?
		// terserah kalian mau ngapain....
	}
	return rebalance(localRoot);
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
			root = insertAVL(root, jack);
		}
		count = 0;
		for(int b=0; b<M; b++){
			scanf("%lld", &jill);
			root = insertAVL(root, jill);
		}
		printf("%lld\n", count);
		root = freeAll(root);
	}
	
	return 0;
}
