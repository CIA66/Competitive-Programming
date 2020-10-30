#include<stdio.h>
#include<math.h>

#define MAXN 100000

int Parent[MAXN + 10];

void makeSet(int n){
	for(int i=0; i<=n; i++){
		Parent[i] = i;
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
	double cost;
};

struct edge arr[100000];

struct Batu{
	int x, y;
}batu[1006];

int main(){
	int N = 0;
	int tc = 1;
	while(1){
		scanf("%d", &N);
		if(N == 0) break;
		makeSet(N);
		int x = 0, y = 0;
		for(int a=0; a<N; a++){
			scanf("%d %d", &x, &y);
			batu[a].x = x;
			batu[a].y = y;
		}
		
		int idx = 0;
		for(int i=0; i<N; i++){
			for(int k=i+1; k<N; k++){
				arr[idx].a = i;
				arr[idx].b = k;
				double tempCost = sqrt( pow((double)batu[k].x - (double)batu[i].x, 2) + pow((double)batu[k].y - (double)batu[i].y, 2) );
				arr[idx].cost = tempCost;
				idx++;
			}
		}
		
		for(int i=idx-1; i>0; i--){
			for(int k=0; k<i; k++){
				if(arr[k].cost > arr[k+1].cost){
					struct edge temp = arr[k];
					arr[k] = arr[k+1];
					arr[k+1] = temp;
				}
			}
		}
		
//		for(int i=0; i<idx; i++){
//			printf(" >. %d - %d : %lf\n", arr[i].a, arr[i].b, arr[i].cost);
//		}
		
		printf("Scenario #%d\n", tc++);
		
		for(int i=0; i<idx; i++){
			if(isSameSet(arr[i].a, arr[i].b)){
				continue;
			}
			merge(arr[i].a, arr[i].b);
			if(isSameSet(0, 1)){
				printf("Frog Distance = %.3lf\n", arr[i].cost);
				break;
			}
//			printf(" Edge MST : %d %d --> %.3lf\n", arr[i].a, arr[i].b, arr[i].cost);
		}
		puts("");
	}
	return 0;
}