#include<stdio.h>

int main(){
	char str[1000];
	while(scanf("%[^\n]", str) != EOF){
		getchar();
		printf("%s\n", str);
	}
	return 0;
}