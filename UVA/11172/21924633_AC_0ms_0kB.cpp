#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	
	int T;
	scanf("%d", &T);
	
	int a, b;
	for(int i = 0; i < T; i++){
		scanf("%d %d", &a, &b);
		
		if(a < b) puts("<");
		else if(a > b) puts(">");
		else if( a == b) puts("=");
	}
	return 0;
}