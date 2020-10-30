#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main(){
	
	priority_queue <int> q;
	int N, x;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &x);
		q.push(-x);
	}
	
	int arr[1006];
	for(int i = 0; i < N; i++){
		arr[i] = -q.top();
		q.pop();
	}
	
	int cont = 0;
	for(int i = 0; i < N; i++){
		if(i == 0) printf("%d", arr[i]);
		else if((arr[i] != arr[i-1]+1) && cont == 0) printf(" %d", arr[i]);
		else if((arr[i] == arr[i-1]+1)){
			cont++;
		}
		else if((arr[i] != arr[i-1]+1) && cont != 0){
			if(cont == 1) printf(" %d", arr[i-1]);
			else printf("-%d", arr[i-1]);
			printf(" %d", arr[i]);
			cont = 0;
		}
	}
	if(cont != 0){
		if(cont == 1) printf(" %d\n", arr[N-1]);
		else printf("-%d\n", arr[N-1]);
	}
	else printf("\n");
	
	
	return 0;
}