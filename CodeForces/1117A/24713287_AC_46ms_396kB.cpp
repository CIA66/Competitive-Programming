#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	
	int n;
	scanf("%d", &n);
	
	int arr[100006];
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}
	
	int maxi = 0, cou = 0, maxCou = 0, now = -1;
	for(int i = 1; i <= n; i++){
		if(arr[i] != now){
			now = arr[i];
			cou = 1;
		}
		else cou++;
		
		if(maxi < now){
			maxi = now;
			maxCou = cou;
//			printf(" -- %d\n", cou);
		}
		else if(now == maxi){
//			printf(" ++ %d\n", arr[i]);
			maxCou = max(cou, maxCou);
			
		}
//		printf("%d\n", cou);
	}
	printf("%d\n", maxCou);
	
	return 0;
}