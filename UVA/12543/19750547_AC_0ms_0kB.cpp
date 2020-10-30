#include<stdio.h>
#include<string.h>

int main(){
	char str[106];
	strcpy(str, "");
	int max = 0;
	char final[106];
	strcpy(final, "");
	while(scanf("%s", str) != EOF){
		if(strcmp(str, "E-N-D") == 0) break;
		int lenStr = strlen(str);
		char word[106];
		strcpy(word, "");
		int b = 0;
		for(int a=0; a<lenStr; a++){
			if(('A' <= str[a] && str[a] <= 'Z')|| ('a' <= str[a] && str[a] <= 'z') || str[a] == '-'){
				word[b] = str[a];
				b++;
			}
		}
		if(b > max){
			max = b;
			strcpy(final, word);
		}
	}
	for(int a=0; a<max; a++){
		if('A' <= final[a] && final[a] <= 'Z'){
			final[a] = final[a] - 'A' + 'a';
		}
	}
	printf("%s\n", final);
	return 0;
}