#include<stdio.h>
#include<string.h>
int main(){
	int T = 0;
	scanf("%d", &T); getchar();
	char str[106];
	for(int a=1; a<=T; a++){
		strcpy(str, "");
		gets(str);
		int len = strlen(str);
		int count = 0;
		for(int b=0; b<len; b++){
			if(str[b] == 'a' || str[b] == 'd' || str[b] == 'g' || str[b] == 'j' || str[b] == 'm' || str[b] == 'p'|| str[b] == 't' || str[b] == 'w' || str[b] == ' '){
				count += 1;
			} else if(str[b] == 'b' || str[b] == 'e' || str[b] == 'h' || str[b] == 'k' || str[b] == 'n' || str[b] == 'q' || str[b] == 'u'|| str[b] == 'x'){
				count += 2;
			} else if(str[b] == 'c' || str[b] == 'f' || str[b] == 'i' || str[b] == 'l' || str[b] == 'o' || str[b] == 'r' || str[b] == 'v'|| str[b] == 'y'){
				count += 3;
			} else if(str[b] == 's' || str[b] == 'z'){
				count += 4;
			}
//			printf("%c   %d\n", str[b], count);
		}
		printf("Case #%d: %d\n", a, count);
	}
	return 0;
}