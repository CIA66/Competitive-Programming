#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll a[300006];
ll score;

int main(){
	
	int n;
	scanf("%d", &n);
	
	score = 0;
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		score += a[i];
	}
	
	sort(a+1, a+1+n);
	
	for(int i = 1; i <= n; i++){
		if(i == n) score += (a[i] * (i - 1));
		else score += (a[i] * i);
	}
	printf("%lld\n", score);
	
	return 0;
}

/*

3
3 1 5


1
10

1 3 5		9
1 | 3 5		9
3 | 5		8
			26

1 3 5 7 9
1 | 3 5 7 9
3 | 5 7 9
5 | 7 9
7 | 9



*/