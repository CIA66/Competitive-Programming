#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node {
	int u;
	int cost;
	struct node *next;
};

struct nodeDijkstra {
	int v;
	int cost;
};

int visited[250005];
struct node *adjList[250005];
const int inf = 1000000000; // a value big enough


void insertToList(struct node **curHead, int u, int cost) {
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->u = u;
	newNode->cost = cost;
	newNode->next = *curHead;
	*curHead = newNode;
}


void freeList(struct node **curHead) {
	while( *curHead != NULL ) {
		struct node *tobedeleted = *curHead;
		*curHead = (*curHead)->next;
		free(tobedeleted);
	}
}



// heap function
int comp(struct nodeDijkstra a, struct nodeDijkstra b) {
	if (a.cost == b.cost) {
		if (a.v < b.v) return -1;
		if (a.v == b.v) return 0;
		if (a.v > b.v) return 1;
	} else {
		if (a.cost < b.cost) return -1;
		if (a.cost > b.cost) return 1;
	}
}

void upHeap(struct nodeDijkstra *arrHeap, int idx) {
	if (idx == 1) return;
	int ParentIdx = idx / 2;
	if (comp(arrHeap[ParentIdx], arrHeap[idx]) > 0) {
		// swap
		
		struct nodeDijkstra temp = arrHeap[ParentIdx];
		arrHeap[ParentIdx] = arrHeap[idx];
		arrHeap[idx] = temp;
		upHeap(arrHeap, ParentIdx);
	}
}


void downHeap(struct nodeDijkstra *arrHeap, int nHeap, int idx) {
	
	int toIdx = idx;
	if (2*idx <= nHeap && comp(arrHeap[2*idx], arrHeap[toIdx]) < 0) {
		toIdx = 2*idx;
	}
	if ( (2*idx+1) <= nHeap && comp(arrHeap[2*idx+1], arrHeap[toIdx]) < 0) {
		toIdx = 2*idx+1;
	}
	
	if (toIdx == idx) return;
	
	// swap
	struct nodeDijkstra temp = arrHeap[toIdx];
	arrHeap[toIdx] = arrHeap[idx];
	arrHeap[idx] = temp;
	downHeap(arrHeap, nHeap, toIdx);
}

void insertToHeap(struct nodeDijkstra *arrHeap, int *nHeap, int u, int cost) {
	if (*nHeap == 0) {
		arrHeap[1].cost = cost;
		arrHeap[1].v = u;
		(*nHeap)++;
		return;
	}
	
	*nHeap = (*nHeap) + 1;
	
	arrHeap[*nHeap].cost = cost;
	arrHeap[*nHeap].v = u;
	
	upHeap(arrHeap, *nHeap);
}

void deleteFromHeap(struct nodeDijkstra *arrHeap, int *nHeap) {
	if (*nHeap == 0) return;
	if (*nHeap == 1) {
		(*nHeap)--;
		return;
	}
	
	// swap dengan root
	struct nodeDijkstra temp = arrHeap[1];
	arrHeap[1] = arrHeap[*nHeap];
	arrHeap[*nHeap] = temp;
	(*nHeap)--;
	downHeap(arrHeap, *nHeap, 1);
}


struct nodeDijkstra heap[600006];
int byknodeheap = 0;

int prim(int nNode, int from) {
	// reset dist dan visited
	for(int i=0; i<nNode; i++) {
		visited[i] = 0;
	}
	// reset heap
	byknodeheap = 0;
	
	insertToHeap(heap, &byknodeheap, from, 0);


	int mstCost = 0;
	//for(int xxxx=0; xxxx<nNode; xxxx++) {
	while(byknodeheap > 0) {
		
		int minIdx = heap[1].v;
		int cost = heap[1].cost;
		deleteFromHeap(heap, &byknodeheap);
		if (visited[minIdx]) continue;
		visited[minIdx] = 1;
		mstCost += cost;
		
		// for all neighbour u of "minIdx" relax them
		struct node *cur = adjList[minIdx];
		while( cur != NULL ) {
			int u = cur->u;
			int edgeCost = cur->cost;

			insertToHeap(heap, &byknodeheap, u, edgeCost);

			cur = cur->next;
		}
	}
	return mstCost;
}

int Roll(char key1[], char key2[]){
	int sum = 0;
	int num1 = 0, num2 = 0;
	
	for(int i=0; i<4; i++){
		num1 = key1[i] - '0';
		num2 = key2[i] - '0';
		
		int temp = 0;
		if(num1 < num2){
			temp = num2 - num1;
			if(temp > 5){
				sum += (10 - temp);
			} else {
				sum += temp;
			}
		} else {
			temp = num1 - num2;
			if(temp > 5){
				sum += (10 - temp);
			} else {
				sum += temp;
			}
		}
	}
	
	return sum;
}

int main(){
	
	int T = 0, N = 0;
	
	scanf("%d", &T);
	
	for(int a=0; a<T; a++){
		scanf("%d", &N);
		
		char key[506][6];
		int idx = 0;
		
		for(int i=0; i<N; i++) {
			adjList[i] = NULL;
		}
		
		for(int i=0; i<N; i++){
			scanf("%s", key[i]);
			
			for(int j=0; j<i; j++){
				int tempRoll = Roll(key[i], key[j]);
				insertToList(&adjList[i], j, tempRoll);
				insertToList(&adjList[j], i, tempRoll);
			}
		}
		
		int minCostFrom0000 = inf;
		
		for(int i=0; i<N; i++){
			int tempRoll = Roll(key[i], "0000");
			if( tempRoll < minCostFrom0000){
				minCostFrom0000 = tempRoll;
			}
		}
		
		int MSTcost = prim(N, 0) + minCostFrom0000;
		
//		if(MSTcost < costNull){
			printf("%d\n", MSTcost);
//		}		
//		else {
//			printf("%d\n", costNull);
//		}
		
		
		for(int i=0; i<N; i++) {
			freeList(&adjList[i]);
		}
	}

	
	return 0;
}
