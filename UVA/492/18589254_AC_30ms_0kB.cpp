#include<stdio.h>
#include<string.h>

	char text[10000006];
int main(){
	char huruf[53] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
	char hidup[11] = "AaIiUuEeOo";
	char L;
	int N = 0;
	int on = 1;
	int temp;
	
	while(true){
		scanf("%c", & text[N]);
		if(text[N] == '\n'){
			printf("%s", text);
			break;
		}
		
		if(N != 0 && strchr(huruf, text[N]) == 0){
			on = 1;
			if(strchr(huruf, text[N-1]) != 0){
				if(strchr(hidup, L) == 0){
					while(temp < N){
						text[temp] = text[temp+1];
						temp++;
					}
					text[N-1] = L;
				}
				L = text[N];
				text[N] = 'a';
				text[N+1] = 'y';
				text[N+2] = L;
				N = N + 2;
			}
				
		}
		else{
			if(on == 1){
				L = text[N];
				temp = N;
				on = 0;
			}
		}
		N++;
	}
	return 0;
}