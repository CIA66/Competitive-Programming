#include<stdio.h>

int main(){
	int n = 0, k = 0;
	while(scanf("%d %d", &n, &k) != EOF){
		int total = n;

		while(n >= k){
			total += n / k;
			n = (n / k) + (n % k);
		}
		printf("%d\n", total);
	}
	return 0;
}