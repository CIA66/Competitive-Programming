#include<stdio.h>
#include<string.h>

char N[1000006];
char temp[1000006];
// 11110001101

int Fangy(char N[]){
	
	int count = 0;
	int len = strlen(N);

	while(len != 1){
		
		if(N[len-1] == '0'){
			// genap
			len--;
		}
		else if(N[len-1] == '1'){
			// ganjil
			int tru = 0;
			for(int i=len-1; i>=0; i--){
				if(i == (len-1)){
					N[i] = '0';
				}
				else{
					if(N[i] == '1'){
						N[i] = '0';
					}
					else if(N[i] == '0'){
						N[i] = '1';
						tru = 1;
						break;
					}
				}
			}
		
			if(tru == 0){
				temp[0] = '1';
				int tempLen = len+1;
				int l;
				for(l=1; l<tempLen; l++){
					temp[l] = N[l-1];
				}
				temp[l] = '\0';
				strcpy(N, temp);
				len = tempLen;
			}
		}
		count++;
//		printf("Count: %d ---- ", count);
//		for(int k=0; k<len; k++){
//			printf("%c", N[k]);
//		}
//		puts("");
	}
	
	return count;
	
}

int main(){
//	while(1){
		gets(N);
		
		printf("%d\n", Fangy(N));
//	}

	return 0;
}