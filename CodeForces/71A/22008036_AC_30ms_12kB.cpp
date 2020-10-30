#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n;
	scanf("%d", &n);
	getchar();
	
	for(int i = 0; i < n; i++){
		char str[106];
		gets(str);
		int len = strlen(str);
		if(len < 11) puts(str);
		else printf("%c%d%c\n", str[0], len-2, str[len-1]);
	}
	
	
	return 0;
}