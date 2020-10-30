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


long long int extractMin(long long int *localArr, long long int *ndata) {
	if ((*ndata) == 0) {
		return 0; // gk ngapa2in
	}
	if ((*ndata) == 1) {
		*ndata = (*ndata) - 1;
		return 1; // sukses delete data
	}
	
	// swap root dengan data di index terakhir
	long long int temp = localArr[1];
	localArr[1] = localArr[*ndata];
	localArr[*ndata] = temp;
	
	*ndata = (*ndata) - 1; // "hilangkan" data terakhir
	
	downHeap(localArr, *ndata, 1); // downheap si root
	
	return 1;
}

int main(){
	long long int N = 0, K = 0, i = 0, A = 0, count = 0;
	
	scanf("%lld %lld", &N, &K);
	for(i = 0; i < N; i++){
		scanf("%lld", &A);
		insertHeap(arr, &jumdata, A);
	}
	
	long long int temp1 = 0, temp2 = 0, total = 0;
	
	while(arr[1] < K){
		if(jumdata >= 2){
			count++;
			temp1 = arr[1];
			extractMin(arr, &jumdata);
			temp2 = arr[1];
			extractMin(arr, &jumdata);
			total = (temp1 + (2*temp2));
			insertHeap(arr, &jumdata, total);
		} else {
			count = -1;
			break;
		}
	}
	
	printf("%lld\n", count);
	
	return 0;
}