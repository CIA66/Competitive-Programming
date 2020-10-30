#include<stdio.h>

int main(){
	int n = 0, m = 0, c = 0, tc = 1;
	while(1){
		scanf("%d %d %d", &n, &m, &c);
		int consump[22] = {0};
		int sequence[22] = {0};
		int down = 0;
		if(n == 0 && m == 0 && c == 0) break;
		for(int a=0; a<n; a++){
			scanf("%d", &consump[a]);
		}
		int device = 0;
		int current = 0, max = 0;
		for(int b=0; b<m; b++){
			scanf("%d", &device);
			if(sequence[device-1] == 0){
				current += consump[device-1];
				sequence[device-1] = 1;
				if(current > max) max = current;
				if(current > c) down = 1;
			}
			else if(sequence[device-1] == 1){
				current -= consump[device-1];
				sequence[device-1] = 0;
			}
		}
		
		printf("Sequence %d\n", tc++);
		if(down == 1) printf("Fuse was blown.\n");
		else printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n", max);
		printf("\n");
	}
	return 0;
}