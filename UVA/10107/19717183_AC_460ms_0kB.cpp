#include<stdio.h>


void merge(long long int X[], int L, int mid, int R){
	long long int temp[10006];
	int left = L, right = mid+1, idx = 0;
	
	while(left <= mid && right <= R){
		if(X[left] < X[right]) temp[idx++] = X[left++];
		else temp[idx++] = X[right++];
	}
	
	int start;
	if(left > mid) start = right;
	else start = left;
	
	int end;
	if(left > mid) end = R;
	else end = mid;
	
	while(start <= end) temp[idx++] = X[start++];
	
	for(int i=0; i<idx; i++){
		X[L++] = temp[i];	
	}
	
}

void mergeSort(long long int X[], int L, int R){
	if(R <= L) return;
	
	int mid = (L+R) / 2;
	mergeSort(X, L, mid);
	mergeSort(X, mid+1, R);
	
	merge(X, L, mid, R);
}


int main(){
	long long int N, X[10006], a = 0;
	while(scanf("%lld", &N) != EOF){
		X[a] = N;
		
		mergeSort(X, 0, a);
		
		if(a % 2 == 0){
			printf("%lld\n", X[a/2]);
		}
		else{
			printf("%lld\n", (X[a/2] + X[a/2 + 1]) / 2);
		}
		a++;
	}
	return 0;
}