#include<stdio.h>
#include<string.h>

int main(){
	
	char S[15];
	int tc = 1;
	while(1){
		scanf("%s", S);
		if(strcmp(S, "#") == 0) break;
		printf("Case %d: ", tc);
		
		if(strcmp(S, "HELLO") == 0) printf("ENGLISH\n");
		else if(strcmp(S, "HOLA") == 0) printf("SPANISH\n");
		else if(strcmp(S, "HALLO") == 0) printf("GERMAN\n");
		else if(strcmp(S, "BONJOUR") == 0) printf("FRENCH\n");
		else if(strcmp(S, "CIAO") == 0) printf("ITALIAN\n");
		else if(strcmp(S, "ZDRAVSTVUJTE") == 0) printf("RUSSIAN\n");
		else printf("UNKNOWN\n");
		tc++;
	}
	return 0;
}