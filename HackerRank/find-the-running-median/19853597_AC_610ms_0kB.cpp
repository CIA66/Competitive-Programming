#include<stdio.h>


const long long int MAXDATA = 100000;
double arrMin[MAXDATA+10];
long long int jumDataMin;

double arrMax[MAXDATA+10];
long long int jumDataMax;


long long int getMin(double *localArr, long long int ndata) {
	// ini asumsi bahwa ndata > 0 selalu terpenuhi
	return localArr[1];
}

long long int getMax(double *localArr, long long int ndata) {
	// ini asumsi bahwa ndata > 0 selalu terpenuhi
	return localArr[1];
}

long long int isEmpty(double *localArr, long long int ndata) {
	return ndata == 0;
}


void upHeapMin(double *localArr, long long int idx) {
	if (idx == 1) return;
	long long int ParentIdx = idx / 2;
	if (localArr[ParentIdx] > localArr[idx]) {
		// swap
		double temp = localArr[ParentIdx];
		localArr[ParentIdx] = localArr[idx];
		localArr[idx] = temp;
		
		
		upHeapMin(localArr, ParentIdx);
	}
}


void downHeapMin(double *localArr, long long int ndata, long long int idx) {
	long long int toIdx = idx;
	if (2*idx <= ndata && localArr[2*idx] < localArr[toIdx]) {
		toIdx = 2*idx;
	}
	if ((2*idx+1) <= ndata && localArr[2*idx+1] < localArr[toIdx]) {
		toIdx = 2*idx + 1;
	}
	
	if (toIdx == idx) return;
	
	// swap
	double temp = localArr[toIdx];
	localArr[toIdx] = localArr[idx];
	localArr[idx] = temp;
	
	downHeapMin(localArr, ndata, toIdx);
}

long long int insertHeapMin(double *localArr, long long int *ndata, double newValue) {
	if ((*ndata) >= MAXDATA) return 0;
	*ndata = (*ndata) + 1;
	localArr[*ndata] = newValue;
	upHeapMin(localArr, *ndata);
	return 1;
}


long long int extractMin(double *localArr, long long int *ndata) {
	if ((*ndata) == 0) {
		return 0; // gk ngapa2in
	}
	if ((*ndata) == 1) {
		*ndata = (*ndata) - 1;
		return 1; // sukses delete data
	}
	
	// swap root dengan data di index terakhir
	double temp = localArr[1];
	localArr[1] = localArr[*ndata];
	localArr[*ndata] = temp;
	
	*ndata = (*ndata) - 1; // "hilangkan" data terakhir
	
	downHeapMin(localArr, *ndata, 1); // downheap si root
	return 1;
}


void upHeapMax(double *localArr, long long int idx) {
	if (idx == 1) return;
	long long int ParentIdx = idx / 2;
	if (localArr[ParentIdx] < localArr[idx]) {
		// swap
		double temp = localArr[ParentIdx];
		localArr[ParentIdx] = localArr[idx];
		localArr[idx] = temp;
		
		
		upHeapMax(localArr, ParentIdx);
	}
}


void downHeapMax(double *localArr, long long int ndata, long long int idx) {
	int toIdx = idx;
	if (2*idx <= ndata && localArr[2*idx] > localArr[toIdx]) {
		toIdx = 2*idx;
	}
	if ((2*idx+1) <= ndata && localArr[2*idx+1] > localArr[toIdx]) {
		toIdx = 2*idx + 1;
	}
	
	if (toIdx == idx) return;
	
	// swap
	int temp = localArr[toIdx];
	localArr[toIdx] = localArr[idx];
	localArr[idx] = temp;
	
	downHeapMax(localArr, ndata, toIdx);
}

long long int insertHeapMax(double *localArr, long long int *ndata, double newValue) {
	if ((*ndata) >= MAXDATA) return 0;
	*ndata = (*ndata) + 1;
	localArr[*ndata] = newValue;
	upHeapMax(localArr, *ndata);
	return 1;
}


long long int extractMax(double *localArr, long long int *ndata) {
	if ((*ndata) == 0) {
		return 0; // gk ngapa2in
	}
	if ((*ndata) == 1) {
		*ndata = (*ndata) - 1;
		return 1; // sukses delete data
	}
	
	// swap root dengan data di index terakhir
	double temp = localArr[1];
	localArr[1] = localArr[*ndata];
	localArr[*ndata] = temp;
	
	*ndata = (*ndata) - 1; // "hilangkan" data terakhir
	
	downHeapMax(localArr, *ndata, 1); // downheap si root
	return 1;
}


int main(){
	long long int N = 0, i = 0;
	double A;
	scanf("%lld", &N);
	for(i = 0; i<N; i++){
		scanf("%lf", &A);
		if(jumDataMax == 0){
			insertHeapMax(arrMax, &jumDataMax, A);
		}
		else if(jumDataMax == jumDataMin){
			if(A < getMin(arrMin, jumDataMin)){
				insertHeapMax(arrMax, &jumDataMax, A);
			} else {
				insertHeapMin(arrMin, &jumDataMin, A);
				insertHeapMax(arrMax, &jumDataMax, getMin(arrMin, jumDataMin));
				extractMin(arrMin, &jumDataMin);
			}
		}
		else if(jumDataMax > jumDataMin){
			if(A > getMax(arrMax, jumDataMax)){
				insertHeapMin(arrMin, &jumDataMin, A);
			} else {
				insertHeapMax(arrMax, &jumDataMax, A);
				insertHeapMin(arrMin, &jumDataMin, getMax(arrMax, jumDataMax));
				extractMax(arrMax, &jumDataMax);
			}
		}
		
		if(jumDataMax == jumDataMin){
			printf("%.1lf\n", (getMin(arrMin, jumDataMin) + getMax(arrMax, jumDataMax)) / 2.0);
		} 
		else {
//			printf("max > min\n");
			double temp = getMax(arrMax, jumDataMax);
			printf("%.1lf\n", temp);
		}
	}
	
	return 0;
}