#include<stdio.h>
#include<string.h>

/*
int keybo(char x){
	
	if(x == '1') return '`';
	else if(x > 49 && x <= 57) return ( x - 1 );
	else if(x == '-') return '0';
	else if(x == '=') return '-';
	
	else if(x == '0') return '9';
	else if(x == 'W' ) return 'Q' ; 
	else if(x == 'E' ) return 'W' ; 
	else if(x == 'R' ) return 'E' ;
	else if(x == 'T' ) return 'R' ;
	else if(x == 'Y' ) return 'T' ;
	else if(x == 'U' ) return 'Y' ;
	else if(x == 'I' ) return 'U' ;
	else if(x == 'O' ) return 'I' ;
	else if(x == 'P' ) return 'O' ;
	else if(x == '[' ) return 'P' ;
	else if(x == ']' ) return '[' ;
	else if(x == '\\' ) return ']' ;
	
	else if(x == 'S' ) return 'A' ;
	else if(x == 'D' ) return 'S' ;
	else if(x == 'F' ) return 'D' ;
	else if(x == 'G' ) return 'F' ;
	else if(x == 'H' ) return 'G' ;
	else if(x == 'J' ) return 'H' ;
	else if(x == 'K' ) return 'J' ;
	else if(x == 'L' ) return 'K' ;
	else if(x == ';' ) return 'L' ;
	else if(x == '\'' ) return ';' ;
	
	else if(x == 'X' ) return 'Z' ;
	else if(x == 'C' ) return 'X' ;
	else if(x == 'V' ) return 'C' ;
	else if(x == 'B' ) return 'V' ;
	else if(x == 'N' ) return 'B' ;
	else if(x == 'M' ) return 'N' ;
	else if(x == ',' ) return 'M' ;
	else if(x == '.' ) return ',' ;
	else if(x == '/' ) return '.' ;
	
	
}

*/

int main(){
	
	char str[100100];
	while(scanf("%[^\n]", str) != EOF){
		getchar();
		int len = strlen(str);
		
		for(int i = 0; i < len; i++){
//			str[i] = keybo(str[i]);
			if(str[i] == '1') printf("`");
			else if(str[i] > 49 && str[i] <= 57) printf("%c", str[i] - 1 );
			else if(str[i] == '-') printf("0");
			else if(str[i] == '=') printf("-");
			
			else if(str[i] == '0') printf("9");
			else if(str[i] == 'W' ) printf("Q");
			else if(str[i] == 'E' ) printf("W"); 
			else if(str[i] == 'R' ) printf("E");
			else if(str[i] == 'T' ) printf("R");
			else if(str[i] == 'Y' ) printf("T");
			else if(str[i] == 'U' ) printf("Y");
			else if(str[i] == 'I' ) printf("U");
			else if(str[i] == 'O' ) printf("I");
			else if(str[i] == 'P' ) printf("O");
			else if(str[i] == '[' ) printf("P");
			else if(str[i] == ']' ) printf("[");
			else if(str[i] == '\\' ) printf("]");
			
			else if(str[i] == 'S' ) printf("A");
			else if(str[i] == 'D' ) printf("S");
			else if(str[i] == 'F' ) printf("D");
			else if(str[i] == 'G' ) printf("F");
			else if(str[i] == 'H' ) printf("G");
			else if(str[i] == 'J' ) printf("H");
			else if(str[i] == 'K' ) printf("J");
			else if(str[i] == 'L' ) printf("K");
			else if(str[i] == ';' ) printf("L");
			else if(str[i] == '\'' ) printf(";");
			
			else if(str[i] == 'X' ) printf("Z");
			else if(str[i] == 'C' ) printf("X");
			else if(str[i] == 'V' ) printf("C");
			else if(str[i] == 'B' ) printf("V");
			else if(str[i] == 'N' ) printf("B");
			else if(str[i] == 'M' ) printf("N");
			else if(str[i] == ',' ) printf("M");
			else if(str[i] == '.' ) printf(",");
			else if(str[i] == '/' ) printf(".");
			
			else printf("%c", str[i]);
		}
		printf("\n");
	}
	
	
	return 0;
}

/*
O S, GOMR YPFSU/
*/


