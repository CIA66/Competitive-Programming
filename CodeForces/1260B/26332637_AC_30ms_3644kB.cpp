#include<bits/stdc++.h>

using namespace std;

#define ll long long

void ans(int a, int b){
	if((a+b) % 3 == 0 && (a*2) >= b) printf("YES\n");
	else printf("NO\n");
}

int main(){
	
	int t;
	scanf("%d", &t);
	while(t--){
		int a, b, c;
		scanf("%d %d", &a, &b);
		if(a > b){
			c = a;
			a = b;
			b = c;
		}
				
		ans(a, b);
	}
	return 0;
}