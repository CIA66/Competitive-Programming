#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int w;
	scanf("%d", &w);
	
	int valid = 0;
	
	int j = w;
	for(int i = 1; i <= w; i++){
		if(i % 2 == 0 && j % 2 == 0){
			valid = 1;
			break;
		}
		w--;
	}
	
	if(valid) puts("YES");
	else puts("NO");
	
	return 0;
}