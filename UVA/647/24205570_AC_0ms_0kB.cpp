#include<stdio.h>

int main(){
	
	int dice[1006], idx = 0;
	while(1){
		scanf("%d", &dice[idx]);
		if(dice[idx] == 0) break;
		idx++;
	}
	
	int a, player[10];
	
	while(1){
		scanf("%d", &a);
		if(a == 0) break;
		
		for(int i = 0; i <= a; i++){
			player[i] = 0;
		}
		
		int papan[106];
		for(int i = 0; i < 101; i++){
			papan[i] = -1;
		}
		
		while(1){
			int s, e;
			scanf("%d %d", &s, &e);
			if(s == 0 && e == 0) break;
			papan[s] = e;
		}
		
		int temp;
		while(1){
			scanf("%d", &temp);
			if(temp == 0) break;
			if(temp < 0){
				temp *= -1;
				papan[temp] = -1000;
			}
			else{
				papan[temp] = 1000;
			}
		}
		
		int now = 1, skip[10], diceCount = 0, ganti = 1;
		
		for(int i = 1; i <= a; i++){
			skip[i] = 0;
		}
		while(1){
			
			if(skip[now] == 1){
				skip[now] = 0;
				now++;
				if(now > a){
					now = 1;
				}
				continue;
			}
			ganti = 1;
			
			if(player[now] >= 95){
				if(player[now] + dice[diceCount] > 100){
					now++;
					if(now > a){
						now = 1;
					}
					continue;
				}
			}
			
			
			if(player[now] >= 100){
				printf("%d\n", now);
				break;
			}
			
			player[now] += dice[diceCount];
//			printf("----\n");
//			for(int i = 1; i <= a; i++){
//				printf("Player %d di %d\n", i, player[i]);
//			}
//			printf("----\n");
			
			if(papan[player[now]] != -1){
				if(papan[player[now]] == -1000){
					skip[now] = 1;
				}
				else if(papan[player[now]] == 1000){
					ganti = 0;
				}
				else{
					player[now] = papan[player[now]];
				}
			}
			if(papan[player[now]] == -1000){
				skip[now] = 1;
			}
			else if(papan[player[now]] == 1000){
				ganti = 0;
			}
			
			if(player[now] >= 100){
				printf("%d\n", now);
				break;
			}
			
			if(ganti) now++;
			if(now > a){
				now = 1;
			}
			diceCount++;
			if(diceCount == idx){
				diceCount = 0;
			}
		}
		
	}
	
	
	return 0;
}

/*

3 6 3 2 5 1 3 4 2 3 1 2 0
2
6 95
99 1
0 0
-3
98
0
2
3 99
6 90
0 0
0
0

*/
