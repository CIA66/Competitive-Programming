#include<stdio.h>
#include<stdlib.h>

struct state {
	int A;
	int B;
};

struct data {
	struct state curState;
	struct data *next;
	struct data *prev;
};


int visited[1010][1010];
struct state prevPath[1010][1010];
int ans[1010][1010];
int countData;


void insertBelakang(struct data **localHead, struct data **localTail, struct state curSt) {
	struct data *newNode = (struct data *)malloc(sizeof(struct data));
	
	newNode->curState = curSt;
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
	countData++;
}


void deleteDepan(struct data **localHead, struct data **localTail) {
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
	countData--;
}

void freeAll(struct data **localHead, struct data **localTail) {
	while(*localHead != NULL) {
		deleteDepan(localHead, localTail);
	}
}

void PrintAns(struct state curState) {
	if (curState.A == 0 && curState.B == 0) return;

	PrintAns(prevPath[curState.A][curState.B]);

	if (ans[curState.A][curState.B] == 1) {
		printf("empty A\n");
	} else if (ans[curState.A][curState.B] == 2) {
		printf("empty B\n");
	} else if (ans[curState.A][curState.B] == 3) {
		printf("fill A\n");
	} else if (ans[curState.A][curState.B] == 4) {
		printf("fill B\n");
	} else if (ans[curState.A][curState.B] == 5) {
		printf("pour A B\n");
	} else if (ans[curState.A][curState.B] == 6) {
		printf("pour B A\n");
	}
}

int bfs(int Acap, int Bcap, int needHowMuch) {
	
	struct data *qhead = NULL;
	struct data *qtail = NULL;
	
	for(int i=0; i<=Acap; i++) {
		for(int k=0; k<=Bcap; k++) {
			visited[i][k] = 0; // reset visited
			prevPath[i][k].A = -1;
			prevPath[i][k].B = -1;
			ans[i][k] = -1;
		}
	}
	countData = 0; // reset si countData
	struct state awal;
	awal.A = 0;
	awal.B = 0;
	
	insertBelakang(&qhead, &qtail, awal);
	
	
	for(int moves=0; qhead != NULL; moves++) {
		
		int dataSize = countData;
		
		for(int x=0; x<dataSize; x++) {
			
			struct state curState = qhead->curState;
			deleteDepan(&qhead, &qtail);
			
			
			if (curState.A == needHowMuch ||
					curState.B == needHowMuch) {
						PrintAns(curState);
						freeAll(&qhead, &qtail);
						return moves;
			}
			
			if (visited[curState.A][curState.B]) {
				continue;
			}
			visited[curState.A][curState.B] = 1;
			
			
			struct state nextState;
			if (curState.A > 0) { // buang air A / empty A
				nextState.A = 0;
				nextState.B = curState.B;
				insertBelakang(&qhead, &qtail, nextState);
				if (prevPath[nextState.A][nextState.B].A == -1) { // berarti belum di set
					prevPath[nextState.A][nextState.B] = curState;
					ans[nextState.A][nextState.B] = 1;
				}
			}
			if (curState.B > 0) { // buang air B / empty B
				nextState.A = curState.A;
				nextState.B = 0;
				insertBelakang(&qhead, &qtail, nextState);
				if (prevPath[nextState.A][nextState.B].A == -1) { // berarti belum di set
					prevPath[nextState.A][nextState.B] = curState;
					ans[nextState.A][nextState.B] = 2;
				}
			}
			if (curState.A < Acap) { // fill A
				nextState.A = Acap;
				nextState.B = curState.B;
				insertBelakang(&qhead, &qtail, nextState);
				if (prevPath[nextState.A][nextState.B].A == -1) { // berarti belum di set
					prevPath[nextState.A][nextState.B] = curState;
					ans[nextState.A][nextState.B] = 3;
				}
			}
			if (curState.B < Bcap) {
				nextState.A = curState.A;
				nextState.B = Bcap;
				insertBelakang(&qhead, &qtail, nextState);
				if (prevPath[nextState.A][nextState.B].A == -1) { // berarti belum di set
					prevPath[nextState.A][nextState.B] = curState;
					ans[nextState.A][nextState.B] = 4;
				}
			}
			if (curState.A > 0) { // kita bisa fill A -> B
				int fill = Bcap - curState.B;
				if (curState.A < fill) {
					fill = curState.A;
				}
				int currentA = curState.A - fill;
				int currentB = curState.B + fill; // ditambah
				nextState.A = currentA;
				nextState.B = currentB;
				insertBelakang(&qhead, &qtail, nextState);
				if (prevPath[nextState.A][nextState.B].A == -1) { // berarti belum di set
					prevPath[nextState.A][nextState.B] = curState;
					ans[nextState.A][nextState.B] = 5;
				}
			}
			if (curState.B > 0) { // kita bisa fill B -> A
				int fill = Acap - curState.A;
				if (curState.B < fill) {
					fill = curState.B;
				}
				int currentA = curState.A + fill; // ditambah
				int currentB = curState.B - fill;
				nextState.A = currentA;
				nextState.B = currentB;
				insertBelakang(&qhead, &qtail, nextState);
				if (prevPath[nextState.A][nextState.B].A == -1) { // berarti belum di set
					prevPath[nextState.A][nextState.B] = curState;
					ans[nextState.A][nextState.B] = 6;
				}
			}
		}
	}
	return -1;
}


int main() {
	int Acap, Bcap, howmuch;
	while(scanf("%d %d %d", &Acap, &Bcap, &howmuch) != EOF) {
		int bykmoves = bfs(Acap, Bcap, howmuch);
		printf("success\n");
	}
	return 0;
}