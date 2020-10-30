#include<stdio.h>
#include<string.h>
char str[100000];
int main(){
	int N = 0;
	scanf("%d", &N);
	for(int a=0; a<N; a++){
		scanf("%s", str);
		int len = strlen(str);
		if(strcmp(str, "1") == 0 || strcmp(str, "4") == 0  || strcmp(str, "78") == 0) printf("+\n");
		else if(str[len-2] == '3' && str[len-1] == '5') printf("-\n");
		else if(str[0] == '9' && str[len-1] == '4') printf("*\n");
		else if(str[0] == '1' && str[1] == '9' && str[2] == '0') printf("?\n");
		
	}
	
	return 0;
}