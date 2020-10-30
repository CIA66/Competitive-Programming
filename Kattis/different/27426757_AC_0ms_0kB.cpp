#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll int a, b, c;

int main(){
	
	while(scanf("%lld %lld", &a, &b) != EOF){
		c = a - b;
		if(c < 0) printf("%lld\n", -c);
		else printf("%lld\n", c);
	}
	
	return 0;
}