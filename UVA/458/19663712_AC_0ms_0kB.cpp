#include<stdio.h>
#include<string.h>
int main(){
//	for(int a = 0; a<200; a++){
//		printf("%c %d\n", a, a);
//	}

//	printf("%c\n", '1' - 7);

	char str[3000];
	while(gets(str)){
		int len = strlen(str);
		for(int a=0; a<len; a++){
			printf("%c", str[a] - 7);
		}
		puts("");
	}
	return 0;
}


