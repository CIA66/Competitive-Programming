#include<stdio.h>
#include<string.h>

int main(){
	
//	printf("%d %d %d\n", '"', '`', '\'');
//	printf("%c %c %c\n", 34, 96, 39);
	
	char input[60] = "";
	
	int flag = 0;
//	/scanf("%s", input) != EOF --> gk bisa
/*
	Main difference between '%s' and 'gets' is:
	%s ends taking input when it encounter whitespace, new line(
	) or EOF.
	gets takes whitespace and stops taking input when it encounters new line(
	) or EOF.
*/

	while(gets(input)){
		char str[60] = "";
		
		int len = strlen(input);
		int b = 0;
		for(int a=0; a<len /*input[a]*/; a++){
			if(input[a] == 34 && flag == 0){
				str[b] = str[b+1] = 96;
				flag = 1;
				b += 2;
			} else if (input[a] == 34 && flag == 1) {
				str[b] = str[b+1] = 39;
				flag = 0;
				b += 2;
			} else {
				str[b] = input[a];
				b++;
			}
		}
		printf("%s\n", str);
	}
	
	return 0;
}