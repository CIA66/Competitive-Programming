#include<stdio.h>
#include<string.h>

int main(){
	
	int N;
	
	scanf("%d", &N); getchar();
	
	for(int i = 0; i < N; i++){
		
		char str[100];
		scanf("%s", str);
		
		int len = strlen(str);
		int skip = 0;
		int a;
		for(a = 1; a <= len; a++){
			
			if(len % a != 0) continue; // yg bukan fakktornya gk usah dicari. Karena substring hanya bisa dicari sejumlah faktornya saja.
			for(int b = a; b < len; b++){
//				printf("%c %c -- a: %d b:%d  b%%a: %d\n", str[b], str[b%a], a, b, b%a);
				if(str[b] != str[b%a]){
//					printf("skip\n");
					skip = 1;
					break;
				}
			}
			if(!skip) break;
			skip = 0;
		}
		printf("%d\n", a);
		if(i != N-1) printf("\n");
	}
	return 0;
}