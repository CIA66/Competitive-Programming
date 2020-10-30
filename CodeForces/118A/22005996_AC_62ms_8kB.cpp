#include<bits/stdc++.h>

int valid(char s){
	if(s == 'A') return 0;
	else if(s == 'a') return 0;
	else if(s == 'O') return 0;
	else if(s == 'o') return 0;
	else if(s == 'Y') return 0;
	else if(s == 'y') return 0;
	else if(s == 'E') return 0;
	else if(s == 'e') return 0;
	else if(s == 'U') return 0;
	else if(s == 'u') return 0;
	else if(s == 'I') return 0;
	else if(s == 'i') return 0;
	return 1;
}

int main(){
	
//	while(1){
		char str[1000];
		gets(str);
		
		int len = strlen(str);
		char ans[1000];
		int idx = 0;
		
		for(int i = 0; i < len; i++){
			if(valid(str[i])){
				ans[idx++] = '.';
				if('A' <= str[i] && str[i] <= 'Z'){
					str[i] += 32;
				}
				ans[idx++] = str[i];
			}
		}
		ans[idx] = '\0';
		puts(ans);
//	}
	
	
	return 0;
}