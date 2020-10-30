#include<stdio.h>

#define ll long long


ll mergee(ll arr[], ll temp[], ll left, ll mid, ll right){
	
	ll countt = 0;
	
	ll i = left, j = mid, k = left;
	
	while((i <= mid-1) && (j <= right)){
		
		if(arr[i] <= arr[j]) temp[k++] = arr[i++];
		else {
			temp[k++] = arr[j++];
			countt += (mid - i);
		}
	}
	
	while(i <= mid-1) temp[k++] = arr[i++];
	
	while(j <= right) temp[k++] = arr[j++];
	
	for(i = left; i <= right; i++){
		arr[i] = temp[i];
	}
	
	return countt;
}

ll mergeeSort(ll arr[], ll temp[], ll left, ll right){
	
	ll countt = 0;
	if(right > left){
		
		ll mid = (left + right) / 2;
		
		countt = mergeeSort(arr, temp, left, mid);
		countt += mergeeSort(arr, temp, mid+1, right);
		
		countt += mergee(arr, temp, left, mid+1, right);
	}
	return countt;
}


ll arr[500006];
ll temp[500006];

int main(){
	
	int N;
	
	while(1){
		scanf("%d", &N);
		if(N == 0) break;
		
		for(int i = 0; i < N; i++){
			scanf("%lld", &arr[i]);
		}
		
		ll sum = mergeeSort(arr, temp, 0, N-1);
		printf("%lld\n", sum);
	}
	
	return 0;
}

/*
5
9
1
0
5
4
3
1
2
3
0
*/