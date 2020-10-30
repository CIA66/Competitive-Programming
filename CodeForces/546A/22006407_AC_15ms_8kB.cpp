#include<bits/stdc++.h>


using namespace std;

int main(){
	
	int k, n, w;
	scanf("%d %d %d", &k, &n, &w);
	
	int sum = 0;
	for(int i = 1; i <= w; i++){
		sum += k*i;
	}
	
	int temp = sum - n;
	if(temp > 0) printf("%d\n", temp);
	else printf("0\n");
	
	return 0;
}