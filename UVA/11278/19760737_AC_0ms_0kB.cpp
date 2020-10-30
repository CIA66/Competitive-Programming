#include<stdio.h>
#include<string.h>

int main(){
	
	char qwe[100] = {"`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>? "};
	char dev[100] = {"`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\" "};
	
	char str[1006];
	while(gets(str)){
		int len = strlen(str);
		for(int a = 0; a<len; a++){
			for(int i=0; i<95; i++){
				if(qwe[i] == str[a]){
					printf("%c", dev[i]);
					break;
				}
			}
		}
		puts("");
	}
	
	return 0;
}