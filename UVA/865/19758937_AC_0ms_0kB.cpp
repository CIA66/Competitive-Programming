#include<stdio.h>
#include<string.h>

struct Data{
	char plain;
	char sub;
}data[100];

int main(){
	int T = 0;
	scanf("%d", &T);
	getchar(); getchar();
	
	char plain[100];
	char sub[100];
	for(int a=0; a<T; a++){
		if(a != 0) puts("");
		
		gets(plain); 
		int len = strlen(plain);
		gets(sub);
		
		for(int b=0; b<len; b++){
			data[b].plain = plain[b];
			data[b].sub = sub[b];
		}
		char word[50];
		int lenWord = 0;
		printf("%s\n", sub); 
		printf("%s\n", plain); 		
		while(gets(word)){
			lenWord = strlen(word);
			if(lenWord == 0) break;
			for(int i=0; i<lenWord; i++){
				for(int j=0; j<len; j++){
					if(word[i] == data[j].plain){
						word[i] = data[j].sub;
						break;
					}
				}
				printf("%c", word[i]);
			}
			puts("");
		}
		
	}
	return 0;
}