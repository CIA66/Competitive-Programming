#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define inf 100000000


int f(int n){
	
	int hasil = 1;
	while(n != 0){
		if(n % 10 != 0){
			hasil *= n%10;
			n /= 10;
		}
		else n /= 10;
	}
	return hasil;
}

int g(int n){
	if(n < 10) return n;
	else return g(f(n));
}

int sum[11][1000100];

void base(){
	
	for(int k = 1; k <= 9; k++){
		int cou = 0;
		for(int j = 1; j <= 1000000; j++){
			if(g(j) == k) cou++;
			
			sum[k][j] = cou;
		}
	}
}


int main(){
	
	base();
	int Q;
	scanf("%d", &Q);
	while(Q--){
		int l, r, k;
		scanf("%d %d %d", &l, &r, &k);
		printf("%d\n", sum[k][r] - sum[k][l-1]);
	}
	
	return 0;
}

/*

*/