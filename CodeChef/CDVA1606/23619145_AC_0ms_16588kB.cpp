// Acc :')

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
	scanf("%d", &T);
	
	for(int i = 0; i < T; i++){
		
		int N, M ,k;
		scanf("%d %d %d", &N, &M, &k);
		
		char str1[100006], str2[100006];
		getchar();
		scanf("%s", str1);
		scanf("%s", str2);

		char key[100006]; int idx = 0;
		for(int j = 0; j < k; j++){
			key[idx] = str2[j];
			idx++;
		}
		key[idx] = '\0';
//		printf("%s\n", key);

		int hasil = KMP(str1, key);
		if(hasil == 0) printf("-1\n");
		else printf("%d\n", hasil);
	}
	
	return 0;
}

/*

2
5 2 2
abcab
ab
5 2 1
abccc
cc

*/