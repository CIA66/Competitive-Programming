#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
	char kata[60];
	struct data *left, *right;
};

char toLower(char x){
	if('A' <= x && x <= 'Z') return x-'A'+'a';
	return x;
}

struct data *newNode(char newKey[]){
	struct data *newNode = (struct data*)malloc(sizeof(struct data));
	strcpy(newNode->kata, newKey);
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
}

struct data *insertData(struct data *currentRoot, char temp[]){
	if(currentRoot == NULL) return newNode(temp);
	
	else if(strcmp(currentRoot->kata, temp) < 0){
		currentRoot->right = insertData(currentRoot->right, temp);
	} 
	else if(strcmp(currentRoot->kata, temp) > 0){
		currentRoot->left = insertData(currentRoot->left, temp);
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