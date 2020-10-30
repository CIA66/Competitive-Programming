#include<stdio.h>


const int MAXDATA = 1000000;
long long int arr[MAXDATA+10];
long long int jumdata;

long long int getMin(long long int *localArr, long long int ndata) {
	// ini asumsi bahwa ndata > 0 selalu terpenuhi
	return localArr[1];
}

long long int isEmpty(long long int *localArr, long long int ndata) {
	return ndata == 0;
}

void upHeap(long long int *localArr, long long int idx) {
	if (idx == 1) return;
	long long int ParentIdx = idx / 2;
	if (localArr[ParentIdx] > localArr[idx]) {
		// swap
		long long int temp = localArr[ParentIdx];
		localArr[ParentIdx] = localArr[idx];
		localArr[idx] = temp;
		
		
		upHeap(localArr, ParentIdx);
	}
}


void downHeap(long long int *localArr, long long int ndata, long long int idx) {
	long long int toIdx = idx;
	if (2*idx <= ndata && localArr[2*idx] < localArr[toIdx]) {
		toIdx = 2*idx;
	}
	if ((2*idx+1) <= ndata && localArr[2*idx+1] < localArr[toIdx]) {
		toIdx = 2*idx + 1;
	}
	
	if (toIdx == idx) return;
	
	// swap
	long long int temp = localArr[toIdx];
	localArr[toIdx] = localArr[idx];
	localArr[idx] = temp;
	
	downHeap(localArr, ndata, toIdx);
}

long long int insertHeap(long long int *localArr, long long int *ndata, long long int newValue) {
	if ((*ndata) >= MAXDATA) return 0;
	*ndata = (*ndata) + 1;
	localArr[*ndata] = newValue;
	upHeap(localArr, *ndata);
	return 1;
}


long long int extractMin(long long int *localArr, long long int *ndata, long long int v) {
	if ((*ndata) == 0) {
		return 0; // gk ngapa2in
	}
	if ((*ndata) == 1) {
		*ndata = (*ndata) - 1;
		return 1; // sukses delete data
	}
	
	long long int idx = 0;
	for(long long int b=1; b<=(*ndata); b++){
		if(arr[b] == v){
			idx = b;
		}
	}
	
	// swap root dengan data di index terakhir
	long long int temp = localArr[idx];
	localArr[idx] = localArr[*ndata];
	localArr[*ndata] = temp;
	
	*ndata = (*ndata) - 1; // "hilangkan" data terakhir
	long long int parentIdx = idx / 2;
	if(parentIdx > 0 && localArr[parentIdx] > localArr[idx]){
		upHeap(localArr, idx);
	} else {
		downHeap(localArr, *ndata, idx); // downheap si root
	}
	return 1;
}


int main() {
	
	int Q = 0, op = 0;
	long long int v = 0;
	
	scanf("%d", &Q);
	for(int a=0; a<Q; a++){
		scanf("%d", &op);
		if(op == 1){
			scanf("%lld", &v);
			insertHeap(arr, &jumdata, v);
		} else if(op == 2){
			scanf("%lld", &v);
			extractMin(arr, &jumdata, v);
		} else if(op == 3){
			printf("%lld\n", getMin(arr, jumdata));
		}
	}
	
	return 0;
}