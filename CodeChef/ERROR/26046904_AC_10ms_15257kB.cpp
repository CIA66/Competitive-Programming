#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	
	int T;
	scanf("%d", &T);
	char S[100006];
	
	while(T--){
		scanf("%s", S);
		int len = strlen(S);
		int val = 0;
		if(len < 3) {
			printf("Bad\n");
			continue;
		}
		for(int i = 0; i < len-2; i++){
			if(S[i] == '0'){
				if(S[i+1] == '1' && S[i+2] == '0'){
					val = 1;
					break;
				}
			}
			else{
				if(S[i+1] == '0' && S[i+2] == '1'){
					val = 1;
					break;
				}
			}
		}
		
		if(val) printf("Good\n");
		else printf("Bad\n");
	}
	return 0;
}