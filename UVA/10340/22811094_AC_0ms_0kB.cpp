#include<bits/stdc++.h>

int main(){
	
	char s[100006], t[100006];
	
	while(scanf("%s %s", s, t) != EOF){
		
		int lenS = strlen(s), lenT = strlen(t);
		
		int idx = 0;
		for(int i = 0; i < lenT; i++){
			
			if(t[i] == s[idx]){
				idx++;
			}
		}
		
		if(idx == lenS) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}