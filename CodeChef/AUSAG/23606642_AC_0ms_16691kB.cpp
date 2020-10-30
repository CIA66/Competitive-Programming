#include<stdio.h>
#include<string.h>



int KMP(char* S, char* s){
//	printf("%s\n", S);
	int lenS = strlen(S);
	int lens = strlen(s);
	
	// Make LPS Table Array
	int lps[100006];
	int a = 1;
	int len = 0;
	while(a < lens){
		
		if(s[len] == s[a]){
			len++;
			lps[a] = len;
			a++;
		}
		else{
			if(len != 0){
				len = lps[len-1];
			}
			else{
				lps[a] = 0;
				a++;
			}
		}
	}
	
//	printf("----\n");
//	for(int x = 0; x < lens; x++){
//		printf("%d ", lps[x]);
//	}
//	printf("\n----\n");
	
	// KMP Search
	int sum = 0;
	int i = 0; // idx buat S
	int j = 0; // idx buat s
	
	while(i < lenS){
		if(S[i] == s[j]){
			i++;
			j++;
		}
		
		if(j == lens){
			sum++;
			j = lps[j - 1];
		}
		else if(i < lenS && S[i] != s[j]){
			
			if(j != 0){
				j = lps[j - 1];
			}
			else{
				i = i + 1;
			}
		}
	}
//	printf("%d\n", sum);
	return sum;
}


int main(){
	
	int T;
	scanf("%d", &T); getchar();
	
	for(int i = 0; i < T; i++){
		char str1[100006], str2[100006], S[100006] = "", s[100006] = "";
		getchar();
		scanf("%[^\n]", str1); // gets(str1);
//		puts(str1);
		int len = strlen(str1);
//		printf("%d\n", len);
		int idx = 0;
		for(int j = 0; j < len; j++){
			if(str1[j] != ' '){
				S[idx] = str1[j];
				idx++;
			}
		}
//		printf("%s\n", S);

		getchar();
		scanf("%[^\n]", str2); // gets(str2);
		len = strlen(str2);
		idx = 0;
		for(int j = 0; j < len; j++){
			if(str2[j] != ' '){
				s[idx] = str2[j];
				idx++;
			}
		}

		printf("Case %d: %d\n", i+1, KMP(S, s));

	}
	
	return 0;
}

/*

4
axb ycz d
abc
ab  cab cabc abc
abc
aab acbaa bbaaz
aab
aaaaaa
aa

*/