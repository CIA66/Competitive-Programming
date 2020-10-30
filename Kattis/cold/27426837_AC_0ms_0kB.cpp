#include<bits/stdc++.h>
using namespace std;

#define ll long long

int a, b, c;

int main(){
	
	scanf("%d", &a);
	for(int i = 0; i < a; i++){
		scanf("%d", &b);
		if(b < 0) c++;
	}
	printf("%d\n", c);
	
	return 0;
}