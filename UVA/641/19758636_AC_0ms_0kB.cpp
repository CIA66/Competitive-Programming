#include<stdio.h>
#include<string.h>

int convert(char x){
	if(x == '_') return 0;
	else if (x == '.') return 27;
	else {
		for(char a = 'a'; a<= 'z'; a++){
			if(x == a){
				return (a - 'a' + 1);
			}
		}
	}
	return -1;
}


int main(){
	int key = 0;
	char message[100];
	int plainText[100] = {0};
	while(1){
		scanf("%d", &key);
		if(key == 0) break;
		
		scanf("%s", message);
		int len = strlen(message);
		
		for(int a=0; a<len; a++){
			int code = convert(message[a]);
//			printf("%d\n", code);
			int idx = (key * a) % len;
			plainText[idx] = (code + a) % 28;
		}
		
		for(int b=0; b< len; b++){
			if(plainText[b] == 0){
				printf("_");
			} else if(plainText[b] == 27){
				printf(".");
			} else {
				for(int i = 1; i < 27; i++){
					if(plainText[b] == i){
						printf("%c", 'a' + i - 1);
					}
				}
			}
		}
		puts("");
		strcpy(message, "");
	}
}

/*
H a v e   a   N i c e   D a y   ! 
33 23 121 79 86 23 10 19 95 01 87 23 79 23 10 18 11 79 27
*/
