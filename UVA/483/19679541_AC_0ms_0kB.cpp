#include<stdio.h>
#include<string.h>

int main(){
	char str[3000];
	char str2[3000];
	char word[300];
	strcpy(str, "");
	while(gets(str)){
		int len = strlen(str);
		int len2 = 0;
		int idx = 0;
		
		strcpy(str2, "");
		int start = 0;
		for(int a=0; a<len; a++){
//			printf("%c\n", str[a]);
			if(str[a] == ' ' || a == len-1){
				if(a == len-1){
					word[idx] = str[a];
					idx++;
				}
				int lenWord = idx;
//				printf("lenWord : %d\n", lenWord);
				
//				printf("start : %d\n", start);
//				printf("spasi\n");
				int b; 
				for(b=start; idx > 0; b++){
					idx--;
					str2[b] = word[idx];
					start++;
				}
				if(a != len-1){
					str2[b] = ' ';
					start++;
				} else if(a == len-1){
					str2[b] = '\0';
				}
//				start++;
//				idx = 0;
				
//				printf("idx after : %d\n", idx);
//				printf("len str2 : %d\n\n", strlen(str2));
			}
			else {
//				printf("idx word : %d\n", idx);
				word[idx] = str[a];
				idx++;
			}
		}
		printf("%s\n", str2);
	}
	return 0;
}