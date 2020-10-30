#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define inf 10000000

int main(){
	
	
	int T;
	scanf("%d", &T);
	
	for(int i = 0; i <T; i++){
		int arr[6];
		int mini = inf, maxi = 0;
		scanf("%d %d %d", &arr[1], &arr[2], &arr[3]);
		int x = arr[1], y = arr[2], z = arr[3];
		if(x < y && x < z){
			arr[1] = -1;
		} else if(y < x && y < z){
			arr[2] = -1;
		} else{
			arr[3] = -1;
		}
		
		if(x > y && x > z){
			arr[1] = -1;
		} else if(y > x && y > z){
			arr[2] = -1;
		} else{
			arr[3] = -1;
		}
		
		for(int j = 1; j <= 3; j++){
			if(arr[j] != -1){
				printf("Case %d: %d\n", i+1, arr[j]);
				break;
			}
		}
		
	}
	return 0;
}