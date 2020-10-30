#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data {
	int nodeidx;
	struct data *next;
	struct data *prev;
};


int visited[50];

void insertBelakang(struct data **localHead, struct data **localTail, int idx, int *countData) {
	struct data *newNode = (struct data *)malloc(sizeof(struct data));
	
	newNode->nodeidx = idx;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	if (*localHead == NULL) {
		*localHead = newNode;
		*localTail = newNode;
	} else {
		(*localTail)->next = newNode;
		newNode->prev = *localTail;
		*localTail = newNode;
	}
	(*countData)++;
}



void deleteDepan(struct data **localHead, struct data **localTail, int *countData) {
	if (*localHead == NULL) {
		return;
	}
	
	if (*localHead == *localTail) {
		free(*localHead);
		*localHead = NULL;
		*localTail = NULL;
	} else {
		*localHead = (*localHead)->next;
		free((*localHead)->prev);
		(*localHead)->prev = NULL;
	}
	(*countData)--;
}
void freeAll(struct data **localHead, struct data **localTail, int *countData) {
	while(*localHead != NULL) {
		deleteDepan(localHead, localTail, countData);
	}
}

int hash(const char *str, int base, int MOD) {
	int len = strlen(str);
	int ans = 0;
	for(int i=0; i<len; i++) {
		// ((str[i] - '0') + 1)
		// ini tuh konversi dari 0 .. 9 ke 1 .. 10
		ans =  ((( (ans%MOD)  + (((str[i] - '0') + 1)%MOD)  )%MOD) * (base%MOD) ) % MOD;
		//ans = (( (ans%MOD) * (base%MOD)) % MOD) + (((str[i]-'0') + 1) % MOD)
	}
	return ans;
}

int bfs(struct data *listHead[], struct data *listTail[], int count[], int fromidx, int bykmoves) {
	
	struct data *qhead = NULL;
	struct data *qtail = NULL;
	
	for(int i=0; i<50; i++) {
		visited[i] = 0;
	}
	int countData = 0; // reset si countData
	
	char fromidxstr[20];
	sprintf(fromidxstr, "%d", fromidx);
	int fromidxhash = hash(fromidxstr, 19, 47);
	
	insertBelakang(&qhead, &qtail, fromidxhash, &countData);
	
	
	for(int moves=0; qhead != NULL && moves <= bykmoves; moves++) {
		
		int dataSize = countData;
		
		for(int x=0; x<dataSize; x++) {
			
			int curidx = qhead->nodeidx;
			deleteDepan(&qhead, &qtail, &countData);

			if (visited[curidx]) {
				continue;
			}
			visited[curidx] = 1;
			
			struct data *current = listHead[curidx];
			while(current != NULL) {
				int nextidx = current->nodeidx;
				if (visited[nextidx]) {
					current = current->next;
				} else {
					insertBelakang(&qhead, &qtail, nextidx, &countData);
					current = current->next;
				}
			}
		}
	}
	int result = 0;
	for(int i=0; i<50; i++) {
		if (visited[i]) {
			result++;
		}
	}
	freeAll(&qhead, &qtail, &countData);
	return result;
}


int main() {
	
	struct data *head[50];
	struct data *tail[50];
	int countdata[50];
	int ncase = 1;
	
	int numConnect;
	while(scanf("%d", &numConnect) != EOF) {
		if(numConnect == 0) break;
		for(int i=0; i<50; i++) {
			head[i] = tail[i] = NULL;
			countdata[i] = 0;
		}
		
		for(int i=0; i<numConnect; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			
			char astr[20], bstr[20];
			sprintf(astr, "%d", a);
			sprintf(bstr, "%d", b);
			// basis 71, ada 97 tempat di hashtable
			int aidxhash = hash(astr, 19, 47);
			int bidxhash = hash(bstr, 19, 47);
			
			//printf(" %d %d\n", aidxhash, bidxhash);
			
			insertBelakang(&head[aidxhash], &tail[aidxhash], bidxhash, &countdata[aidxhash]);
			insertBelakang(&head[bidxhash], &tail[bidxhash], aidxhash, &countdata[bidxhash]);
		}
		
		int byknodes = 0;
		for(int i=0; i < 50; i++) {
			if (head[i] != NULL) byknodes++;
		}
		
		int a, moves;
		while(scanf("%d %d", &a, &moves) != EOF) {
			if (a == 0 && moves == 0) break;
			int howmany = bfs(head, tail, countdata, a, moves);
//			printf(" >> %d\n", howmany);
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ncase++, byknodes-howmany, a, moves);
		}
		
		for(int i=0; i<50; i++) {
			freeAll(&head[i], &tail[i], &countdata[i]);
		}
	}

	return 0;
}