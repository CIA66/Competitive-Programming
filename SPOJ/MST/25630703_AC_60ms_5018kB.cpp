#include<bits/stdc++.h>

using namespace std;
#define ll long long

#define MAXN 100000

int Parent[MAXN + 10];

void makeSet(int n){
	for(int i=1; i<=n; i++){
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

struct Edge{
	int a, b;
	int cost;
};
bool compare(Edge A, Edge B){
	return A.cost < B.cost;
}

struct Edge arr[MAXN+10];

int main(){

	int V, E, aa, bb, cc;
	
	scanf("%d %d", &V, &E);
	
	for(int r = 0; r < V; r++){
		Parent[r] = 0;
	}
	makeSet(V);
	
	for(int i = 0; i < E; i++){
		scanf("%d %d %d", &aa, &bb, &cc);
		arr[i].a = aa;
		arr[i].b = bb;
		arr[i].cost = cc;
	}
	ll MST_Cost = 0;
	
//	for(int i = 0; i < E; i++){
//		printf("%d %d - %d\n", arr[i].a, arr[i].b, arr[i].cost);
//	}

//	sort
	std::sort(arr, arr+E, compare);

//	printf("-----\n");
//	for(int i = 0; i < E; i++){
//		printf("%d %d - %d\n", arr[i].a, arr[i].b, arr[i].cost);
//	}
	
	for(int i = 0; i < E; i++){
		if(isSameSet(arr[i].a, arr[i].b)){
			continue;
		}
		MST_Cost += arr[i].cost;
		merge(arr[i].a, arr[i].b);
//		printf(" -- %lld\n", MST_Cost);
	}
	
	printf("%lld\n", MST_Cost);
	
	return 0;
}
