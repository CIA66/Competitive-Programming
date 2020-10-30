#include<stdio.h>

#define ll long long

int main(){
	
	int N;
	scanf("%d", &N);
	unsigned int s, d, a, b, temp;
	
	while(N--){
		scanf("%u %u", &s, &d);
		if((s+d) % 2 == 1 || (s-d) % 2 == 1 || d > s){
			printf("impossible\n");
			continue;
		}
		b = (s - d) / 2;
		a = s - b;
		
		if(a < 0 || b < 0){
			printf("impossible\n");
			continue;
		}
		if(b > a){
			temp = a;
			a = b;
			b = temp;
		}
		printf("%u %u\n", a, b);
	}
	
	return 0;
}