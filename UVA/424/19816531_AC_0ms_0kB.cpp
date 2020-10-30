#include<stdio.h>
#include<string.h>

int main(){
	char str[1000];
	int max = 0;
	int num[160] = {0};
	while(1){
		strcpy(str, "");
		scanf("%s", str);
		if(strcmp(str, "0") == 0) break;
		
		int len = strlen(str);
		int b = 0;
		for(int a=len-1; a>=0; a--){
			num[b] += str[a] - '0';
//			printf("%d\n", num[b]);
			b++;
		}
		if(b > max){
			max = b;
		}
	}
//	printf("max1 : %d\n", max);
	int c = 0;
	for(c=0; c<max; c++){
		if(num[c] > 9){
			num[c+1] += num[c] / 10;
			num[c] %= 10;
			if(c == max-1){
				max++;
				break;
			}
		}
	}
//	printf("max2 : %d\n", max);
	int done = 0;
	for(int d = max-1; d >= 0; d--){
		if(done == 0){
			if(num[d] == 0){
				continue;
			} else {
				done = 1;
				printf("%d", num[d]);
			}
		} else {
			printf("%d", num[d]);
		}
	}
	if(done == 0){
		printf("0");
	}
	puts("");
	return 0;
}