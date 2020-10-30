#include<stdio.h>

int f(int n){
	
	int num = 1;
	
	while(n){
		
		if(n%10 != 0){
			num *= (n%10);
		}
		n /= 10;
	}
	
	return num;
}

int g(int n){
	
	if(n < 10){
		return n;
	}
	else{
		return g(f(n));
	}
}

int total[11][1000006];

void tampung(){
	
	
	for(int k=1; k<=9; k++){
		
		int count = 0;
		for(int x=1; x<1000001; x++){
			
			if(g(x) == k){
				count++;
			}
			
			total[k][x] = count;
		}
	}
}

int main(){
	
	tampung();
	
	int Q;
	int l, r, k;

	scanf("%d", &Q);
	
	for(int i = 0; i<Q; i++){
		
		scanf("%d %d %d", &l, &r, &k);
		
		printf("%d\n", (total[k][r] - total[k][l-1]) );
	}
	return 0;
}