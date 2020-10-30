#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
	int T = 0;
	scanf("%d", &T); getchar();
	char str[10006];
	char grid[106][106];
	for(int a=0; a<T; a++){
		gets(str);
		int len = strlen(str);
		int n = sqrt(len);
		if(n*n == len){
//			printf("n : %d\n", n);
			int idx = 0;
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					grid[i][j] = str[idx];
					idx++;
				}
			}
//			for(int i=0; i<n; i++){
//				for(int j=0; j<n; j++){
//					printf("%c ", grid[i][j]);
//				}
//				puts("");
//			}
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					printf("%c", grid[j][i]);
				}
			}
			puts("");
		}
		else {
			printf("INVALID\n");
		}
	}
	return 0;
}