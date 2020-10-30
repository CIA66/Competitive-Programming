#include<stdio.h>

void sum(int count[11], int x){
	if(x == 0) count[x]++;
	else if(x == 1) count[x]++;
	else if(x == 2) count[x]++;
	else if(x == 3) count[x]++;
	else if(x == 4) count[x]++;
	else if(x == 5) count[x]++;
	else if(x == 6) count[x]++;
	else if(x == 7) count[x]++;
	else if(x == 8) count[x]++;
	else if(x == 9) count[x]++;
}

int main(){
	int T = 0;
	scanf("%d", &T);
	for(int a=0; a<T; a++){
		int count[11] = {0};
		int N = 0;
		
		scanf("%d", &N);
		
		for(int b=1; b<=N; b++){
			if(b < 10){
				sum(count, b);
			} else {
				int now = b;
				while(now > 0){
					sum(count, now%10);
					now /= 10;
				}
			}
		}
		for(int c=0; c<9; c++){
			printf("%d ", count[c]);
		}
		printf("%d\n", count[9]);
	}
	return 0;
}