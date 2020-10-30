// Acc

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

void sort(char arr[][26], int n){
	
	char temp[26];
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
	
	int T, N, start = 1, stat = 1;;
	char list[1006][26];
	int ss = 0;
	
	scanf("%d", &T);
	getchar();
	
	while(T--){
		if(start) start = 0;
		else if(!start) getchar();
		
		scanf("%d", &N); getchar();
		while(N--){
			scanf("%s", list[ss]);
			if(strcmp(list[ss], "XXXXXX") == 0) break;
			ss++;
		}
		
		char str[26], ans[1006][26]; int an = 0;
		while(1){
			an = 0;
			scanf("%s", str);
			if(strcmp(str, "END") == 0) break;
			
			for(int k = 0; k < ss; k++){
				if(isAnagram(str, list[k])){
					strcpy(ans[an], list[k]);
					an++;
				}
			}
			printf("Anagrams for: %s\n", str);
			if(an == 0) printf("No anagrams for: %s\n", str);
			else if(an == 1) printf("  1) %s\n", ans[0]);
			else {
//				sort(ans, an);
				for(int p = 0; p < an; p++){
					printf("  %d) %s\n", p+1, ans[p]);
				}
			}
		}
		if(T != 0) printf("\n");
	}
	
	
	
	
	return 0;
}