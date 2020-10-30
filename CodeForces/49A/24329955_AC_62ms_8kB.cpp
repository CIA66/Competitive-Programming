#include<bits/stdc++.h>

using namespace std;

char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y'};

int main(){
	char str[106];
	scanf("%[^\n]", str);
	int len = strlen(str), found = -1;
	for(int k = len-1; k >= 0; k--){
		if('A' <= str[k] & str[k] <= 'Z'){
			str[k] += 32;
		}
		if('a' <= str[k] & str[k] <= 'z'){
			for(int i = 0; i < 6; i++){
//				printf("%c\n", vowels[i]);
				if(str[k] == vowels[i]){
					found = 1;
					break;
				}
			}
			if(found == -1) found = 0;
		}
		if(found == 1 || found == 0){
			break;
		}
	}
	
	if(found == 1) printf("YES\n");
	else printf("NO\n");
	
	return 0;
}