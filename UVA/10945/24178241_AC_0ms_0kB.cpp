#include<stdio.h>
#include<string.h>


int isPalindrome(char str[], int len){
	
	if(len == 0) return 1;
	for(int i = 0, k = len-1; i < len/2; i++, k--){
		if(str[i] != str[k]){
			return 0;
		}
	}
	
	return 1;
}

char asli[10000], str[10000];

int main(){
	
	while(1){
		scanf("%[^\n]", asli);
		if(strcmp(asli, "DONE") == 0) break;
		int len = strlen(asli);
		
		int idx = 0;
		for(int i = 0; i < len; i++){
			
			if('a' <= asli[i] && asli[i] <= 'z'){
				str[idx] = asli[i];
				idx++;
			}
			else if('A' <= asli[i] && asli[i] <= 'Z'){
				str[idx] = asli[i] + 32;
				idx++;
			}
			
		}
		str[idx] = '\0';
//		printf("%s\n", str);
		int lenn = strlen(str);
		if(isPalindrome(str, lenn)){
			printf("You won\'t be eaten!\n");
		}
		else printf("Uh oh..\n");
		getchar();
	}
	return 0;
}
/*

Madam, Im adam!
Roma tibi subito motibus ibit amor.
Me so hungry!
Si nummi immunis
DONE
*/