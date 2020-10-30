#include<bits/stdc++.h>

using namespace std;

char str[106][26];

int main(){
	
	int N;
	scanf("%d", &N); getchar();
	int count = 0, ada = 0;
	while(N--){
		ada = 0;
		scanf("%[^\n]", str[count]); getchar();
		for(int i = 0; i < count; i++){
			if(strcmp(str[i], str[count]) == 0){
				ada = 1;
				break;
			}
		}
		if(!ada) count++;
	}
	printf("%d\n", count);
	
	return 0;
}