#include<stdio.h>
#include<string.h>

int main(){
	char str[1000];
	
	while(gets(str)){
		int len = strlen(str);
		
		for(int a=0; a<len; a++){
			if(str[a] == '=') str[a] = '0';
            else if(str[a] == '-') str[a] = '9';
            else if(str[a] == '0') str[a] = '8';
            else if(str[a] == '9') str[a] = '7';
            else if(str[a] == '8') str[a] = '6';
            else if(str[a] == '7') str[a] = '5';
            else if(str[a] == '6') str[a] = '4';
            else if(str[a] == '5') str[a] = '3';
            else if(str[a] == '4') str[a] = '2';
            else if(str[a] == '3') str[a] = '1';
            else if(str[a] == '2') str[a] = '`';
			
			else if(str[a] == '\\') str[a] = '[';
			else if(str[a] == ']') str[a] = 'p';
            else if(str[a] == '[') str[a] = 'o';
            else if(str[a] == 'p' || str[a] == 'P') str[a] = 'i';
            else if(str[a] == 'o' || str[a] == 'O') str[a] = 'u';
            else if(str[a] == 'i' || str[a] == 'I') str[a] = 'y';
            else if(str[a] == 'u' || str[a] == 'U') str[a] = 't';
            else if(str[a] == 'y' || str[a] == 'Y') str[a] = 'r';
            else if(str[a] == 't' || str[a] == 'T') str[a] = 'e';
            else if(str[a] == 'r' || str[a] == 'R') str[a] = 'w';
            else if(str[a] == 'e' || str[a] == 'E') str[a] = 'q';
	
            else if(str[a] == '\'') str[a] = 'l';
            else if(str[a]==';') str[a] = 'k';
            else if(str[a]=='l' || str[a]=='L') str[a] ='j';
            else if(str[a]=='k' || str[a]=='K') str[a] = 'h';
            else if(str[a]=='j' || str[a]=='J') str[a] = 'g';
            else if(str[a]=='h' || str[a]=='H') str[a] = 'f';
            else if(str[a]=='g' || str[a]=='G') str[a] = 'd';
            else if(str[a]=='f' || str[a]=='F') str[a] = 's';
            else if(str[a]=='d' || str[a]=='D') str[a] = 'a';
            
            else if(str[a]=='/') str[a] = ',';
            else if(str[a]=='.') str[a] = 'm';
            else if(str[a]==',') str[a] = 'n';
            else if(str[a]=='m' || str[a]=='M') str[a] = 'b';
            else if(str[a]=='n' || str[a]=='N') str[a] = 'v';
            else if(str[a]=='b' || str[a]=='B') str[a] = 'c';
            else if(str[a]=='v' || str[a]=='V') str[a] = 'x';
            else if(str[a]=='c' || str[a]=='C') str[a] = 'z';
		}
		printf("%s\n", str);
	}
	return 0;
}