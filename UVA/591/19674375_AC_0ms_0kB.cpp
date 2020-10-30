#include<stdio.h>
#include<string.h>

int main(){
	int n = 0, tc = 1;
	while(1){
		int h[56] = {0};
		scanf("%d", &n);
		if(n == 0) break;
		int sum = 0;
		for(int a=0; a<n; a++){
			scanf("%d", &h[a]);
			sum += h[a];
		}
		int all = sum / n;
		int min = 0;
		for(int b=0; b<n; b++){
			if(h[b] > all){
				min += (h[b] - all);
			}
		}
		printf("Set #%d\n", tc++);
		printf("The minimum number of moves is %d.\n\n", min);
	}
	return 0;
}