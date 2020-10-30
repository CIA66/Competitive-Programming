#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	
	char str[10];
	int tc = 1;
	while(gets(str)){
		if(strcmp(str, "*") == 0) break;
		if(strcmp(str, "Hajj") == 0) printf("Case %d: Hajj-e-Akbar\n", tc++);
		else printf("Case %d: Hajj-e-Asghar\n", tc++);
	}
	return 0;
}