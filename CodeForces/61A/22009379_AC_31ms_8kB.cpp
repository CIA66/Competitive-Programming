#include<bits/stdc++.h>


int main(){
	
	char str1[106], str2[106], ans[106];
	gets(str1);
	gets(str2);
	
	int len = strlen(str1);
	
	int i;
	for(i = 0; i < len; i++){
		if(str1[i] != str2[i]) ans[i] = '1';
		else ans[i] = '0'; 
	}
	ans[i] = '\0';
	puts(ans);
	
	return 0;
}