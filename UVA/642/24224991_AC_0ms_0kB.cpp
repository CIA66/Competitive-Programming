#include<stdio.h>
#include<string.h>


#define NO_OF_CHARS 256

int isAnagram(char str1[], char str2[]){
	
	int len1 = strlen(str1), len2 = strlen(str2);
	if(len1 != len2) return 0;
	
	int count[NO_OF_CHARS] = {0};
	int i;
	for(i = 0; i < len1 ; i++){
		count[str1[i]]++;
		count[str2[i]]--;
	}
		
	for(i = 0; i < NO_OF_CHARS; i++){
		if(count[i])
			return 0;
	}
	return 1;
}

void sort(char arr[][10], int n){
	
	char temp[86];
	for(int i = 0; i < n; i++){
		for(int k = n-1; k > i; k--){
			if(strcmp(arr[i], arr[k]) > 0){
				strcpy(temp, arr[i]);
				strcpy(arr[i], arr[k]);
				strcpy(arr[k], temp);
			}
		}
	}
	
}

int main(){
	
	char list[106][10];
	int ss = 0;
	while(1){
		
		scanf("%s", list[ss]);
		if(strcmp(list[ss], "XXXXXX") == 0) break;
		ss++;
	}
	char str[10], ans[106][10]; int an = 0;
	while(1){
		an = 0;
		scanf("%s", str);
		if(strcmp(str, "XXXXXX") == 0) break;
		
		for(int k = 0; k < ss; k++){
			if(isAnagram(str, list[k])){
				strcpy(ans[an], list[k]);
				an++;
			}
		}
		if(an == 0) printf("NOT A VALID WORD\n");
		else if(an == 1) printf("%s\n", ans[0]);
		else {
			sort(ans, an);
			for(int p = 0; p < an; p++){
				printf("%s\n", ans[p]);
			}
		}
		printf("******\n");
	}
	
	
	return 0;
}