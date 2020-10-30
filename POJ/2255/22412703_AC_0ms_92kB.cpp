#include<stdio.h>
#include<string.h>

int root;
void print(char str1[], char str2[], int left, int right){
//	printf("%d %d\n", left, right);
	int idx = 0;
	
	if(left > right) return;
	
	for(int i = left; i <= right; i++){
		if(str1[root] == str2[i]){
			idx = i;
			break;
		}
	}
//	printf("idx : %d\n", idx);
	root++;
	print(str1, str2, left, idx-1);
	print(str1, str2, idx+1, right);
	printf("%c", str2[idx]);
	
}


int main(){
	
	char str1[30], str2[30];
	
	while(scanf("%s %s", &str1, &str2) != EOF){
		int len = strlen(str1);
		root = 0;
		print(str1, str2, 0, len-1);
		printf("\n");
	}
	
	return 0;
}

/*

DBACEGF ABCDEFG
BCAD CBAD

*/