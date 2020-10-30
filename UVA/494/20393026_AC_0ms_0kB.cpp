#include<stdio.h>
#include<string.h>

int main(){
	
	char str[1000];
	int lenStr = 0;
	int count = 0;
	int idxStr = 0, idxWord = 0;
	
	while(gets(str)){
		
		count = 0, idxStr = 0, idxWord = 0;
		
		lenStr = strlen(str);
		
		int isWord = 0;
		
		for(int i=0; i<lenStr; i++){
			
			if( ('A' <= str[i] && str[i] <= 'Z') || ('a' <= str[i] && str[i] <= 'z') ){
				
				if(isWord == 0){
					
					isWord = 1;
					count++;
				}
			}
			else{
				isWord = 0;
			}
		}
		
		printf("%d\n", count);
		
	}
	
	return 0;
}