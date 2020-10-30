#include<stdio.h>
#include<string.h>

char str[1000001];

int main(){
	int N = 0, tc = 1;
	while(scanf("%s", str) != EOF){
		getchar();
		if(strcmp(str, "\n") == 0) break;
		scanf("%d", &N);
		
		printf("Case %d:\n", tc++);
		int i, j;
		for(int a=0; a<N; a++){
			scanf("%d %d", &i, &j);
			if(i == j){
				printf("Yes\n");
			}
			else {
				int x = 0, y = 0, sama = 1;
				if(i < j){
					x = i;
					y = j;
				} else {
					x = j;
					y = i;
				}
				for(int a=x; a<y; a++){
					if(str[a] != str[y]){
						sama = 0;
						break;
					}
				}
				if(!sama) printf("No\n");
				else printf("Yes\n");
			}
		}
	}
	return 0;
}