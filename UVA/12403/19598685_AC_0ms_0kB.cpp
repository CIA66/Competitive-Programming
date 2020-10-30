#include<stdio.h>
#include<string.h>

int main(){
	int T;
	char operation[16];
	int money = 0;
	int total = 0;
	scanf("%d", &T);
	for(int a=0; a<T; a++){
		scanf("%s", operation);
		if(strcmp(operation, "donate") == 0){
			scanf("%d", &money);
			total += money;
		} else {
			printf("%d\n", total);
		}
	}	
	return 0;
}