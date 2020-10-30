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

char rev(char xx){
	
	if(xx == 'A') return 'A';
	else if(xx == 'E') return '3';
	else if(xx == 'H') return 'H';
	else if(xx == 'I') return 'I';
	else if(xx == 'J') return 'L';
	else if(xx == 'L') return 'J';
	
	else if(xx == 'M') return 'M';
	else if(xx == 'O') return 'O';
	else if(xx == 'S') return '2';
	else if(xx == 'T') return 'T';
	else if(xx == 'U') return 'U';
	else if(xx == 'V') return 'V';
	else if(xx == 'W') return 'W';
	else if(xx == 'X') return 'X';
	
	else if(xx == 'Y') return 'Y';
	else if(xx == 'Z') return '5';
	else if(xx == '1') return '1';
	else if(xx == '2') return 'S';
	else if(xx == '3') return 'E';
	else if(xx == '5') return 'Z';
	else if(xx == '8') return '8';
	else return '-';
}

int isMirror(char str[], int len){
	int i, k;
	for(i = 0, k = len-1; i < len/2; i++, k--){
		if(rev(str[i]) != str[k]){
			return 0;
		}
	}
	if(len % 2 == 1){
		if(rev(str[i]) != str[k]){
			return 0;
		}
	}
	
	return 1;
}

int main(){
	
	char str[26];
	while(scanf("%s", &str) != EOF){
		
		int len = strlen(str);
		int pal = isPalindrome(str, len);
		int mir = isMirror(str, len);
		
		if(pal && mir) printf("%s -- is a mirrored palindrome.\n\n", str);
		else if(pal) printf("%s -- is a regular palindrome.\n\n", str);
		else if(mir) printf("%s -- is a mirrored string.\n\n", str);
		else printf("%s -- is not a palindrome.\n\n", str);
	}
	
	return 0;
}
/*
NOTAPALINDROME
ISAPALINILAPASI
2A3MEAS
ATOYOTA
*/