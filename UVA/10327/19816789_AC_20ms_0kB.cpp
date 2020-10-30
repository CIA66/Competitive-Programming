#include<stdio.h>
#include<string.h>

int main(){
	int N = 0;
	while(scanf("%d", &N) != EOF){
		int list[1006] = {0};
		int list2[1006] = {0};
		for(int a=0; a<N; a++){
			scanf("%d", &list[a]);
			list2[a] = list[a];
		}
		int count = 0;
		for(int b=0; b<N-1; b++){
			for(int c=0; c<N-b-1; c++){
				if(list[c] > list[c+1]){
					count++;
					int temp = list[c+1];
					list[c+1] = list[c];
					list[c] = temp;
				}
			}
		}
		printf("Minimum exchange operations : %d\n",count);
	}
	return 0;
}