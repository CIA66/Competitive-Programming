#include<bits/stdc++.h>

using namespace std;

int lvl(char str[]){
	// Rock-paper-scissors 
	if(strcmp(str, "rock") == 0) return 1;
	else if(strcmp(str, "paper") == 0) return 2;
	else if(strcmp(str, "scissors") == 0) return 3;
}

int main(){
	
	char Fyodor[16], Matroskin[16], Sharic[16];
	int F, M, S;
	scanf("%s", Fyodor);
	scanf("%s", Matroskin);
	scanf("%s", Sharic);
	
	F = lvl(Fyodor);
	M = lvl(Matroskin);
	S = lvl(Sharic);
	
	if(F == 1 && M == 3 && S == 3) printf("F\n");
	else if(F == 2 && M == 1 && S == 1) printf("F\n");
	else if(F == 3 && M == 2 && S == 2) printf("F\n");
	
	else if(M == 1 && F == 3 && S == 3) printf("M\n");
	else if(M == 2 && F == 1 && S == 1) printf("M\n");
	else if(M == 3 && F == 2 && S == 2) printf("M\n");
	
	else if(S == 1 && M == 3 && F == 3) printf("S\n");
	else if(S == 2 && M == 1 && F == 1) printf("S\n");
	else if(S == 3 && M == 2 && F == 2) printf("S\n");
	else printf("?\n");
	
	return 0;
}