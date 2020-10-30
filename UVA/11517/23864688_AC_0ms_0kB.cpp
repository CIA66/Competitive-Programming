#include<stdio.h>

int min(int a, int b){
	if(a < b) return a;
	return b;
}

#define inf 10000000

int mem[20100];

int main(){
	
	int tc;
	scanf("%d", &tc);
	
	int coin[106];
	
	for(int t = 0; t < tc; t++){
		
		int money, N;
		scanf("%d", &money);
		scanf("%d", &N);
		
		for(int i = 0; i < N; i++){
			scanf("%d", &coin[i]);
		}
		
		for(int i = 0; i < 20100; i++){
			mem[i] = inf;
		}
		
		mem[0] = 0;
		
		for(int i = 0; i < N; i++){
			for(int j = money; j >= 0; j--){
				mem[j+coin[i]] = min(mem[j]+1, mem[j+coin[i]]);
			}
		}
		
		for(int i = money; i <= 30000; i++){
			
			if(mem[i] < 10000){
				printf("%d %d\n", i, mem[i]);
				break;
			}
		}
	}
	
	return 0;
}


/*

1
1400
3
500
1000
2000

*/