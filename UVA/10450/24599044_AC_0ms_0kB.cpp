#include<bits/stdc++.h>

#define ll long long

ll fibo[100];

void base(){
	fibo[1] = 2;
	fibo[2] = 3;
	for(int i = 3; i < 51; i++){
		fibo[i] = fibo[i-1] + fibo[i-2];
	}
}

int main(){
	base();
	int n;
	scanf("%d", &n);
	int tc = 1, num;
	while(n--){
		scanf("%d", &num);
		printf("Scenario #%d:\n", tc);
		printf("%lld\n\n", fibo[num]);
		tc++;
	}
	return 0;
}