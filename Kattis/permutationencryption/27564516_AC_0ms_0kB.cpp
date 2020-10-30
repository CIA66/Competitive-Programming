#include<bits/stdc++.h>

using namespace std;

	
int n, key[26];

int main(){
	
	while(1){
		
		scanf("%d", &n); getchar();
		if(n == 0) break;
		for(int i = 0; i < n; i++){
			scanf("%d", &key[i]);
		}
		for(int i = 0; i < n; i++){
			key[i]--;
		}
		getchar();
		char message[10006];
//		strcpy(message, "");
		
		scanf("%[^\n]", message);
		int len = strlen(message);
		
		double x = (double)len / n;
		int y = (int) ceil(x);
		
		int q = 0;
		printf("'");
		for(int k = 1; k <= y; k++){
			for(int l = 0; l < n; l++){
				if(message[key[l]+q] == '\0'){
					printf(" ");
				}
				else{
					printf("%c", message[key[l]+q]);
				}
			}
			q += n;
		}
		printf("'\n");
		getchar();
		memset(message,'\0',len);
	}
	
	return 0;
}