#include<stdio.h>
#include<string.h>

int main(){
	char input[10];
	int tc = 1;
	while(1){
		scanf("%s", input);
		if(strcmp(input, "*") == 0) break;
		printf("Case %d: ", tc);
		if(strcmp(input, "Hajj") == 0) printf("Hajj-e-Akbar\n");
		else if(strcmp(input, "Umrah") == 0) printf("Hajj-e-Asghar\n");
		tc++;
	}
	return 0;
}