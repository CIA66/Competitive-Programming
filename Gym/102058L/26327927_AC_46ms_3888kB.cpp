#include<bits/stdc++.h>

#define ll long long

int isPalindrome(char str[], int len){
	
	for(int i = 0, k = len-1; i < len/2; i++, k--){
		if(str[i] != str[k]){
			return 0;
		}
	}
	
	return 1;
}

int main(){
	
	char X[250006];
	int k;
	scanf("%s", X); getchar();
	scanf("%d", &k);
	int len = strlen(X);
	
	if(isPalindrome(X, len)){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	
	return 0;
}