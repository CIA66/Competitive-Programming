#include<bits/stdc++.h>

using namespace std;
#define inf 1000000
#define ll long long

int main(){
	
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		
		int f;
		scanf("%d", &f);
		int size, animal, envi;
		int sum = 0;
		for(int j = 0; j < f; j++){
			scanf("%d %d %d", &size, &animal, &envi);
			sum += (size * envi);
		}
		printf("%d\n", sum);
	}
	
	return 0;
}