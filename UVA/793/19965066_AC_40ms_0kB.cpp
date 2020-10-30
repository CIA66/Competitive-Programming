#include<stdio.h>
#include<string.h>


#define MAXN 100	//sebanyak node yg kita mau

int Parent[MAXN + 10];

void makeSet(int n){
	for(int i=1; i<=n; i++){ 
		Parent[i] = i;
	}
}

int findParent(int x){
	if(Parent[x] == x) return x;
	return Parent[x] = findParent(Parent[x]);	// optimization
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

struct edge arr[1000];

int main(){
	int T = 0;
	scanf("%d", &T);
	for(int a=0; a<T; a++){
		int N = 0;
		scanf("%d", &N);
		getchar();
		
		makeSet(N);
		char str[16];
		char token[6]; int comp1 = 0, comp2 = 0;
		int su = 0, un = 0;
		while(gets(str)){
			if(strlen(str) == 0){
				break;
			}
//			printf("%s\n", str);
			sscanf(str, "%s %d %d", token, &comp1, &comp2);
//			printf("%s %d %d\n", token, comp1, comp2);

			if(strcmp(token, "c") == 0){
				merge(comp1, comp2);
			} else if(strcmp(token, "q") == 0){
				int temp = isSameSet(comp1, comp2);
				if(temp == 1){
					su++;
				} else {
					un++;
				}
			}
		}
		printf("%d,%d\n", su, un);
		if(a != T-1) puts("");
//		printf("done\n");
	}

	return 0;
}