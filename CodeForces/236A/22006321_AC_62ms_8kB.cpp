#include<bits/stdc++.h>


using namespace std;

int main(){
	int arr[30];
	for(int q = 0; q < 30; q++){
		arr[q] = 0;
	}
	
	char str[106];
	gets(str);
	
	int len = strlen(str);
	
	for(int i = 0; i < len; i++){
		arr[str[i] - 'a']++;
	}
	int count = 0;
	for(int j = 0; j < 26; j++){
		if(arr[j] > 0) count++;
	}
	if(count % 2 == 0) puts("CHAT WITH HER!");
	else puts("IGNORE HIM!");
	
	return 0;
}