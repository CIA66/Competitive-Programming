#include<stdio.h>

#define MAXN 200000

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
struct edge{
	int a, b;
	int cost;
};

struct edge arr[200006];
struct edge temp[200006];

void merge(struct edge arr[], int left, int mid, int right){
	int L = left;
	int R = mid+1;
	int idx = 0;
	
	while(L<=mid && R<=right){
		if(arr[L].cost < arr[R].cost){
			temp[idx] = arr[L];
			idx++, L++;
		}else{
			temp[idx] = arr[R];
			idx++, R++;
		}
	}
	
	int start;
	if(L > mid){
		start = R;
	}else{
		start = L;
	}
	
	int end;
	if(L > mid){
		end = right;
	}else{
		end = mid;
	}
	
	while(start <= end){
		temp[idx] = arr[start];
		idx++, start++;
	}
	for(int i=0; i<idx; i++){
		arr[left] = temp[i];
		left++;
	}
}

void mergeSort(struct edge arr[], int left, int right){
	if(left >= right) {
		return;
	}
	int mid = (left+right)/2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid+1, right);
	merge(arr, left, mid, right);
}

int main(){
	while(1){
		int M = 0, N = 0;
		scanf("%d %d", &M, &N);
		if(M == 0 && N == 0) break;
		
		for(int r=0; r<M; r++){
			Parent[r] = 0;
		}
		makeSet(M);
		
		long long int before = 0, after = 0;
		int x = 0, y = 0, z = 0;
		
		for(int i=0; i<N; i++){
			scanf("%d %d %d", &x, &y, &z);
			before += z;
			
			arr[i].a = x;
			arr[i].b = y;
			arr[i].cost = z;
		}
		mergeSort(arr, 0, N-1);
//		for(int i=0; i<N; i++){
//			printf("%d - %d : %d\n", arr[i].a, arr[i].b, arr[i].cost);
//		}
		
		for(int i=0; i<N; i++){
			if(isSameSet(arr[i].a, arr[i].b)){
				continue;
			}
			after += arr[i].cost;
			merge(arr[i].a, arr[i].b);
		}
		
		printf("%lld\n", before-after);
	}
	
	
	return 0;
}