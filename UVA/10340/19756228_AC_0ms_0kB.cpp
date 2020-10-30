#include<stdio.h>
#include<string.h>

char str1[1000006], str2[1000006];

int main(){
	
	while(scanf("%s %s", str1, str2) != EOF){
		long long int idx1 = 0, idx2 = 0;
		long long int len1 = strlen(str1);
		long long int len2 = strlen(str2);
		long long int count = 0, a = 0, b = 0;
		for(a=0; a<len2; a++){
			if(str2[a] == str1[b]){
				count++;
				b++;
			}
		}
		if(count == len1){
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}