#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define inf 100000000


int fibo[1100100];
void base(){
	
	fibo[1] = 0;
	fibo[2] = 1;
	for(int i = 3; i <= 1100000; i++){
		fibo[i] = (fibo[i-1] + fibo[i-2]) % 100000;
	}
}


int main(){
	
	base();
	int T, tc = 1;
	scanf("%d", &T);
	while(T--){
		int A, B;
		scanf("%d %d", &A, &B);
		
		priority_queue<int> q;
		int idx = 1;
		for(ll i = A; i <= (A+B); i++){
			q.push(fibo[i] * -1);
			idx++;
//			printf("%d\n", fibo[i] );
		}
		
		printf("Case %d:", tc);
		tc++;
		for(int i = 1; i < idx; i++){
			if(i == 101) break;
			printf(" %d", q.top() * -1);
			q.pop();
		}
		printf("\n");
	}
	
	return 0;
}

/*

*/