#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define MAXN 200000


struct ST{
	int a, b;
	ll val;
}arr[MAXN*4];


void initST(int rootIdx, int a, int b){
	
	arr[rootIdx].a = a;
	arr[rootIdx].b = b;
	
	if(a == b){
		scanf("%d", &arr[rootIdx].val);
		return;
	}
	
	int mid = (a + b) / 2;
	initST(2*rootIdx, a, mid);
	initST(2*rootIdx+1, mid+1, b);
	
	arr[rootIdx].val = arr[2*rootIdx].val + arr[2*rootIdx+1].val;
}

ll getSum(int rootIdx, int a, int b){
	
	if(arr[rootIdx].a == a && arr[rootIdx].b == b){
		return arr[rootIdx].val;
	}
	
	int mid = (arr[rootIdx].a + arr[rootIdx].b) / 2;
	
	if(arr[rootIdx].a <= a && b <= mid){
		return getSum(2*rootIdx, a, b);
	}
	else if(mid+1 <= a && b <= arr[rootIdx].b){
		return getSum(2*rootIdx+1, a, b);
	}
	else{
		return getSum(2*rootIdx, a, mid) + getSum(2*rootIdx+1, mid+1, b);
	}
}

void setValue(int rootIdx, int idx, int newVal){
	
	if(arr[rootIdx].a == idx && arr[rootIdx].b == idx){
		arr[rootIdx].val = newVal;
		return;
	}
	
	int mid = (arr[rootIdx].a + arr[rootIdx].b) / 2;
	
	if(arr[rootIdx].a <= idx && idx <= mid){
		setValue(2*rootIdx, idx, newVal);
	}
	else if(mid+1 <= idx && idx <= arr[rootIdx].b){
		setValue(2*rootIdx+1, idx, newVal);
	}
	arr[rootIdx].val = arr[2*rootIdx].val + arr[2*rootIdx+1].val;
}


int main(){
	
	int tc = 1;
	
	while(1){
		
		int N;
		
		scanf("%d", &N);
		if(N == 0) break;
		
		initST(1, 1, N);
		
		if(tc != 1) printf("\n");
		printf("Case %d:\n", tc++);
		
		char cmd[6];
		
		while(1){
			scanf("%s", cmd);
			if(strcmp(cmd, "END") == 0) {
				break;
			}
			
			int x, y;
			scanf("%d %d", &x, &y);
			
			if(strcmp(cmd, "S") == 0){
				setValue(1, x, y);
			}
			else if(strcmp(cmd, "M") == 0){
				printf("%lld\n", getSum(1, x, y));
			}
		}
	}
	
	return 0;
}