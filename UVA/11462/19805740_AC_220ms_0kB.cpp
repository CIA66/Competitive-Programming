#include<stdio.h>

int main(){
	long long int age[106];
	long long int N = 0, a = 0, b = 0, curr = 0, count = 0;
	while(1){
		
		for(int i=1; i<=100; i++){
			age[i] = 0;
		}
		
		scanf("%lld", &N);
		if(N == 0) break;
		for(a=0; a<N; a++){
			scanf("%lld", &curr);
			++age[curr];
		}
		count = 0;
		for(b = 1; b<100; b++){
			if(age[b] > 0){
				while(age[b] != 0){
					if(count == N-1) printf("%lld", b);
					else printf("%lld ", b);
					count++;
					age[b]--;
				}
			}
		}
		puts("");
	}
	return 0;
}