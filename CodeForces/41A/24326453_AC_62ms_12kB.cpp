#include<bits/stdc++.h>

using namespace std;


int main(){
	
	char str1[1000], str2[1000];
	scanf("%s", str1);
	scanf("%s", str2);
	int len1 = strlen(str1), len2 = strlen(str2), found = 1;
	if(len1 != len2) printf("NO\n");
	else{
		int k = 0;
		for(int i = len1-1; i >= 0; i--){
			if(str1[i] != str2[k]){
				printf("NO\n");
				found = 0;
				break;
			}
			k++;
		}
		if(found) printf("YES\n");
	}
		
	return 0;
}