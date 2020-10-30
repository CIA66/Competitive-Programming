#include<stdio.h>
#include<string.h>


char convert(char x){
	if(x == 'B' || x == 'P' || x == 'F' || x == 'V') return '1';
	else if(x == 'C' || x == 'S' || x == 'K' ||x == 'G' || x == 'J' || x == 'Q' || x == 'X' ||x == 'Z') return '2';
	else if(x == 'D' || x == 'T') return '3';
	else if(x == 'L') return '4';
	else if(x == 'M' || x == 'N') return '5';
	else if(x == 'R') return '6';
	else return '0';
}

int main(){
	char name[30];
	
	printf("         NAME                     SOUNDEX CODE\n");

	while(gets(name)){
		printf("         %-25s%c", name, name[0]);
		
		int len = strlen(name);
		int b = 0;
		int before = convert(name[0]);
//		printf("before  :   %d\n", before);
		int temp = 0;
		for(int a=1; a < len && b < 3; a++){
			temp = convert(name[a]);
			if(temp != '0' && temp != before){
				printf("%c", temp);
				b++;
			}
			before = temp;
		}
		
		while(b < 3){
			printf("0");
			b++;
		}
		puts("");
	}
	printf("                   END OF OUTPUT\n");
	
	return 0;
}

/*
H a v e   a   N i c e   D a y   ! 
33 23 121 79 86 23 10 19 95 01 87 23 79 23 10 18 11 79 27
*/
