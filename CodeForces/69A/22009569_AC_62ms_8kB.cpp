#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n;
	scanf("%d", &n);
	int a = 0, b = 0, c = 0;
	int x, y, z;
	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &x, &y, &z);
		a += x, b += y, c += z;
	}
	if(a == 0 && b == 0 && c == 0) printf("YES\n");
	else printf("NO\n");
	return 0;
}