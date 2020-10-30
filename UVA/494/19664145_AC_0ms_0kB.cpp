#include<stdio.h>
#include<string.h>

int main(){
	char str[3000];
	while(gets(str)){
		
		int count = 0;
		int cut = 0;
		int len = strlen(str);
		for(int a=0; a<len; a++){
			if( 'A' <= str[a] && str[a] <= 'Z' || 'a' <= str[a] && str[a] <= 'z'){
				cut = 1;
			}
			else {
				if(cut == 1){
					cut = 0;
					count++;
				}
			}
		}
		printf("%d\n", count);
		strcpy(str, "");
	}
	return 0;
}