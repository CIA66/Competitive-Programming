#include<stdio.h>
#include<string.h>

int isPalindrome(char str[], int len){
	
	for(int i = 0, k = len-1; i < len/2; i++, k--){
		if(str[i] != str[k]){
			return 0;
		}
	}
	
	return 1;
}

int pernah(char list[][86], int idx, char sub[]){
//	printf("%d\n", idx);
	for(int i = 0; i < idx-1; i++){
//		printf("%s %s\n", list[i], sub);
		if(strcmp(list[i], sub) == 0) return 1;
	}
	return 0;
}

void subStr(char str[], int n){
	char list[3800][86];
	int count = 0, idx = 0, length = 0;
	char sub[86];
	for(int len = 1; len <= n; len++){
		for(int i = 0; i <= n - len; i++){
			int j = i + len - 1;
			idx = 0;
			for(int k = i; k <= j; k++){
				sub[idx] = str[k];
				idx++;
//				printf("%c", str[k]);
			}
			sub[idx] = '\0';
			strcpy(list[length], sub);
			length++;
			if(pernah(list, length, sub)) {
//				printf("skippp\n");
				continue;
			}
			int xx = strlen(sub);
			if(isPalindrome(sub, xx)){
//				printf("%s\n", sub);
				count++;
			}
//			printf("\n");
		}
	}
	printf("The string '%s' contains %d palindromes.\n", str, count);
}

int main(){
	
	char str[86];
	while(gets(str)){
		int len = strlen(str);
//		printf("%d\n", len);
		
		subStr(str, len);
		
	}
	return 0;
}

/*

boy
adam
madam
tot

*/