#include<stdio.h>
#include<string.h>
	
	char str[1100100];
	char str2[1100100];

int main(){
	
	while(1){
		
		scanf("%s", str);
		if(strcmp(str, "END") == 0) break;
		
		int len, count = 1;
		
		len = strlen(str);
		while(1){
			
//			printf("%d\n", len);

			sprintf(str2, "%d", len);
			if(strcmp(str2, str) == 0){
				printf("%d\n", count);
				break;
			}
//			printf("%s\n", str2);
			count++;
			
			strcpy(str, str2);
			len = strlen(str2);
//			getchar();
		}
		
	}
	return 0;
}

// 42