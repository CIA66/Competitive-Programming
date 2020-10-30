#include<bits/stdc++.h>
using namespace std;
#define ll long long

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(){
//	printf("%d\n", gcd(36, 45));

	int n;
	scanf("%d", &n);
	
	if(n < 3) printf("No\n");
	else{
		printf("Yes\n");
		int k;
		if(n % 2 == 0) k = n / 2;
		else if(n % 2 == 1) k = (n / 2) + 1;
		printf("1 %d\n", k);
		printf("%d", n-1);
		for(int i = 1; i <= n; i++){
			if(i == k) continue;
			printf(" %d", i);
		}
		printf("\n");
	}
	return 0;
}