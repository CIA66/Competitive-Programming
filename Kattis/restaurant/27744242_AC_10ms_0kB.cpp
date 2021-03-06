#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int N, x, start = 0;
	char cmd[16];
	
	while(1){
		scanf("%d", &N);
		if(N == 0) break;
		
		if(start > 0){
			printf("\n");
		}
		start++;
		
		int pile1 = 0, pile2 = 0;
		
		for(int i = 0; i < N; i++){
			scanf("%s %d", cmd, &x);
			
			if(cmd[0] == 'D'){
				printf("DROP 2 %d\n", x);
				pile2 += x;
			}
			else{
				
				if(pile1 >= x){
					printf("TAKE 1 %d\n", x);
					pile1 -= x;
				}
				else{
					if(pile1){
						printf("TAKE 1 %d\n", pile1);
						x -= pile1;
						pile1 = 0;
					}
					
					printf("MOVE 2->1 %d\n", pile2);
					pile1 += pile2;
					pile2 = 0;
					
					if(x){
						printf("TAKE 1 %d\n", x);
						pile1 -= x;
					}
				}
			}
		}
	}
	return 0;
}