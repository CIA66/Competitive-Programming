#include<stdio.h>

int main(){
	int T = 0, N = 0, height = 0;
	scanf("%d", &T);
	for(int a = 1; a <= T; a++){
		scanf("%d", &N);
		int highJump = 0, lowJump = 0;
		int heightBefore = 0;
		for(int b = 0; b < N; b++){
			scanf("%d", &height);
			if(heightBefore == 0) heightBefore = height;
			else{
				if(height < heightBefore){
					lowJump++;	
					heightBefore = height;
				}
				else if(height > heightBefore){
					highJump++;
					heightBefore = height;
				}
				else {
					heightBefore = height;
				}
			}
			
		}
		printf("Case %d: %d %d\n", a, highJump, lowJump);
	}
	return 0;
}