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
	
	
	char huruf[30] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 
	'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	
	int T, N;
	
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		scanf("%d", &N);
		
		char jadi[10006];
		int idx = 0, j;
		for(j = 0; j < N; j++){
			if(j % 26 == 0){
				idx = 0; 
			}
			jadi[j] = huruf[idx];
			idx++;
		}
		jadi[j] = '\0';
		printf("%s\n", jadi);
	}
	
	
	
	return 0;
}