#include<bits/stdc++.h>
using namespace std;
#define ll long long

int binser(int arr[], int l, int r, int x){
	
	if(r >= l){
		int mid = l + (r - l) / 2;
		
		if(arr[mid] == x) return mid;
		if(arr[mid] > x) return binser(arr, l, mid-1, x);
		return binser(arr, mid+1, r, x);
	}
	
	return -1;
}

int main(){
	
	int N, Q;
	scanf("%d %d", &N, &Q);

	int numbers[100006];
	
	for(int i = 0; i < N; i++){
		scanf("%d", &numbers[i]);
	}

	int num;
	while(Q--){
		scanf("%d", &num);
		int temp = binser(numbers, 0, N-1, num);
		int i = temp;
		while(i > 0){
			if(numbers[i-1] == numbers[temp]){
				i--;
			}
			else{
				break;
			}
		}
		printf("%d\n", i);
	}
	
	
	return 0;
}

/*

5 4
2 4 7 7 9
7
10
4
2

*/