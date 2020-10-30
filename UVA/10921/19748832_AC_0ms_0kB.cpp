#include<stdio.h>
#include<string.h>

int main(){
	char C[36];
	char str[36];
	strcpy(C, "");
	strcpy(str, "");
	while(gets(C)){
		int len = strlen(C);
//		printf("len : %d\n", len);
		
		for(int a=0; a<len; a++){
//			printf("test\n");
			
			if(C[a] == 'A' || C[a] == 'B' || C[a] == 'C'){
				str[a] = '2';
			}
			else if(C[a] == 'D' || C[a] == 'E' || C[a] == 'F'){
				str[a] = '3';
			}
			else if(C[a] == 'G' || C[a] == 'H' || C[a] == 'I'){
				str[a] = '4';
			} 
			else if(C[a] == 'J' || C[a] == 'K' || C[a] == 'L'){
				str[a] = '5';
			} 
			else if(C[a] == 'M' || C[a] == 'N' || C[a] == 'O'){
				str[a] = '6';
			}
			else if(C[a] == 'P' || C[a] == 'Q' || C[a] == 'R' || C[a] == 'S'){
				str[a] = '7';
			}  
			else if(C[a] == 'T' || C[a] == 'U' || C[a] == 'V'){
				str[a] = '8';
			}  
			else if(C[a] == 'W' || C[a] == 'X' || C[a] == 'Y' || C[a] == 'Z'){
				str[a] = '9';
			}
			else {
				str[a] = C[a];
			}
		}
		for(int b=0; b<len; b++){
			printf("%c", str[b]);
		}
		puts("");
//		printf("%s\n", str);
		strcpy(C, "");
		strcpy(str, "");
	}
	return 0;
}