#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	
	char str[1000];
	char str2[1000];
	int first = 1;
	while(gets(str)){
		
		int len = strlen(str);
		
		int idx = 0;
		for(int i = 0; i < len; i++){
			if(str[i] == '"'){
				if(first){
					str2[idx++] = '`';
					str2[idx++] = '`';
					first = 0;
				}
				else{
					str2[idx++] = '\'';
					str2[idx++] = '\'';
					first = 1;
				}
			}
			else str2[idx++] = str[i];
		}
		str2[idx] = '\0';
		puts(str2);
	}
	
	return 0;
}