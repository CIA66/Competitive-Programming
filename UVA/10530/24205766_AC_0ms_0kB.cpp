#include<stdio.h>
#include<string.h>

int main(){
	
	int num[12];
	for(int i = 0; i <= 10; i++){
		num[i] = 1;
	}
	int N; char str1[6], str2[6];
	while(1){
		scanf("%d", &N); getchar();
		if(N == 0) break;
		scanf("%s %s", str1, str2);
		if(str2[0] == 'h'){
			
			for(int i = N; i <= 10; i++){
				num[i] = 0;
			}
		}
		else if(str2[0] == 'l'){
			for(int i = N; i >= 0; i--){
				num[i] = 0;
			}
		}
		else{
			if(num[N] == 1) printf("Stan may be honest\n");
			else if(num[N] == 0) printf("Stan is dishonest\n");
			for(int i = 0; i <= 10; i++){
				num[i] = 1;
			}
		}
	}
	return 0;
}