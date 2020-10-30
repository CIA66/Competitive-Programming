#include<stdio.h>
#include<math.h>

#define MAXN 100000
#define ll long long

long long int d[MAXN+5], del[MAXN+5];

void generate(){
	
	d[0] = 0;
	del[0] = 0;
	
	for(int i = 1; i <= MAXN; i++){
		
		ll count = 0;
		ll sum = 0;
		
		for(int j = 1; j <= sqrt(i); j++){
			if(i % j == 0){
				count++;
				sum += j;
				
				if(i / j != j){
					count++;
					sum += (i / j);
				}
			}
			
		}
		d[i] = count;
		del[i] = sum;
//		printf("i : %d  count : %d  sum : %d\n", i, count, sum);
//		if(i == 20) getchar();
//		if(i % 100 == 0 )printf("\\\n");
	}
//	printf("END\n");
}

int main(){
	
	generate();
	
	int T;
	scanf("%d", &T);
	
	
	for(int i=0; i < T; i++){
		int a, b, k;
		
		scanf("%d %d %d", &a, &b, &k);
		
		long long int g = 0, h = 0;
		
		for(int i = a; i <= b; i++){
			if(i % k == 0){
				g += d[i];
				h += del[i];
			}
		}
		
		printf("%lld %lld\n", g, h);
	}
	return 0;
}