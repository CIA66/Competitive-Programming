#include<stdio.h>
#include<string.h>


int main(){
	char str1[100];
	char str2[100];
	int T = 0;
	scanf("%d", &T); getchar();
	for(int a=0; a<T; a++){
		strcpy(str1, "");
		while(gets(str1)){
			int len = strlen(str1);
			if(len == 0) break;
			int b = 0;
			for(int a=0; a<len; a++){
				if(str1[a] == '1') str2[b] = 'I';
				else if(str1[a] == '2') str2[b] = 'Z';
				else if(str1[a] == '3') str2[b] = 'E';
				else if(str1[a] == '4') str2[b] = 'A';
				else if(str1[a] == '5') str2[b] = 'S';
				else if(str1[a] == '6') str2[b] = 'G';
				else if(str1[a] == '7') str2[b] = 'T';
				else if(str1[a] == '8') str2[b] = 'B';
				else if(str1[a] == '9') str2[b] = 'P';
				else if(str1[a] == '0') str2[b] = 'O';
				else str2[b] = str1[a];
				b++;
			}
			str2[b] = '\0';
			printf("%s\n", str2);
			strcpy(str2, "");
		}
		if(a != T-1) puts("");
	}
	
	return 0;
}