#include<stdio.h>
#include<stdlib.h>

struct node {
	int u;
	int cost;
	struct node *next;
};

struct nodeDijkstra {
	int v;
	int cost;
};

int dist[20005];
int visited[20005];
struct node *adjList[20005];
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


struct nodeDijkstra heap[45000];
int byknodeheap = 0;

void dijkstra(int nNode, int from) {
	// reset dist dan visited
	for(int i=0; i<nNode; i++) {
		visited[i] = 0;
		dist[i] = inf;
	}
	// reset heap
	byknodeheap = 0;
	
	// dari from -> from = 0
	dist[from] = 0;
	insertToHeap(heap, &byknodeheap, from, dist[from]);


	//for(int xxxx=0; xxxx<nNode; xxxx++) {
	while(byknodeheap > 0) {
		
		int minIdx = heap[1].v;
		deleteFromHeap(heap, &byknodeheap);
		visited[minIdx] = 1;
		
		// for all neighbour u of "minIdx" relax them
		struct node *cur = adjList[minIdx];
		while( cur != NULL ) {
			int u = cur->u;
			int edgeCost = cur->cost;

			if ( (dist[minIdx] + edgeCost) < dist[u]) {
				// update the dist table
				dist[u] = dist[minIdx] + edgeCost;
				insertToHeap(heap, &byknodeheap, u, dist[u]);

			}
			cur = cur->next;
		}
	}

}

int main(){
	int N = 0;
	int n, m, S, T;
	int x, y, w;
	
	scanf("%d", &N);
	for(int a=1; a<=N; a++){
		scanf("%d %d %d %d", &n, &m, &S, &T);
		
		for(int i=0; i<n; i++) {
			adjList[i] = NULL;
		}
		
		for(int b=0; b<m; b++){
			scanf("%d %d %d", &x, &y, &w);
			insertToList(&adjList[x], y, w);	// klo directed 1 arah
			insertToList(&adjList[y], x, w);	// klo undirected bisa 2 arah
		}
		
		dijkstra(n, S);
		
		printf("Case #%d: ", a);
		if (dist[T] >= inf) {
			printf("unreachable\n");
		} else {
			printf("%d\n", dist[T]);
		}
		
		for(int i=0; i<n; i++) {
			freeList(&adjList[i]);
		}
	}
	return 0;
}