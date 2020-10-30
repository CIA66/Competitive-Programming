#include<bits/stdc++.h>

#define ll long long

using namespace std;

int isPalindrome(char str[], int len){
	
	for(int i = 0, k = len-1; i < len/2; i++, k--){
		if(str[i] != str[k]){
			return 0;
		}
	}
	
	return 1;
}

int main(){
	
	char str[250010];
	ll k;
	scanf("%s", str);
	scanf("%lld", &k);
	
	int len = strlen(str); getchar();
	
	int valid = isPalindrome(str, len);
	if(!valid) printf("NO\n");
	else{
		printf("YES\n");
	}
	return 0;
}