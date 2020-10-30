#include<stdio.h>
#include<string.h>

int main(){
	int T = 0;
	
	scanf("%d", &T);
	getchar();
	
	for(int a=0; a<T; a++){
		char train[120] = "";
		gets(train);
		int len = strlen(train);
	
		int male = 0, female = 0;
		for(int b=0; b<len; b++){
			if(train[b] == 'M') male++;
			else if(train[b] == 'F') female++;
		}
		if(male != female || len <= 3) printf("NO LOOP\n");
		else printf("LOOP\n");
		
	}
	return 0;
}