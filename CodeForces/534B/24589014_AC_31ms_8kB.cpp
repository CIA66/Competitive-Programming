#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define inf 100000000



int main(){
	
	int v1, v2, t, d;
	scanf("%d %d", &v1, &v2);
	scanf("%d %d", &t, &d);
	
	int now = v1;
	for(int i = 1; i <= t-2; i++){
		now += min(v1 + i*d, v2 + (t-1)*d - i*d);
	}
	now += v2;
	printf("%d\n", now);
	return 0;
}

/*

*/