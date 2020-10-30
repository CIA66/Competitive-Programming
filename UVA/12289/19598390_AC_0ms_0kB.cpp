#include<stdio.h>
#include<string.h>

int main(){
	char word[11];
	int T = 0;
	scanf("%d", &T);
	for(int a=0; a<T; a++){
		scanf("%s", word);
		if(strcmp(word, "one") == 0) printf("1\n");
		else if(strcmp(word, "two") == 0) printf("2\n");
		else if(strcmp(word, "three") == 0) printf("3\n");
		else if((word[0] == 'o' && word[1] == 'n') || (word[0] == 'o' && word[2] == 'e') || (word[1] == 'n' && word[2] == 'e')) printf("1\n");
		else if((word[0] == 't' && word[1] == 'w') || (word[0] == 't' && word[2] == 'o') || (word[1] == 'w' && word[2] == 'o')) printf("2\n");
		else if(word[0] == 't' && word[1] == 'h' && word[2] == 'r' && word[3] == 'e') printf("3\n");
		else if(word[0] == 't' && word[1] == 'h' && word[2] == 'r' && word[4] == 'e') printf("3\n");
		else if(word[0] == 't' && word[1] == 'h' && word[3] == 'e' && word[4] == 'e') printf("3\n");
		else if(word[0] == 't' && word[2] == 'r' && word[3] == 'e' && word[4] == 'e') printf("3\n");
		else if(word[1] == 'h' && word[2] == 'r' && word[3] == 'e' && word[4] == 'e') printf("3\n");
	}
	return 0;
}