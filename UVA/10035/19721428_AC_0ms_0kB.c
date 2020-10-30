#include<stdio.h>

int main(){
	long long int first, second;
	
	while(scanf("%lld %lld", &first, &second) != EOF){
		if(first == 0 && second == 0) break;
		
		int carry = 0, after = 0, temp = 0;
		while(first > 0 || second > 0){
			temp = (first % 10) + (second % 10) + after;
			if(temp > 9){
				carry++;
				after = 1;
			} else {
				after = 0;
			}
			first /= 10;
			second /= 10;
		}
		if(carry == 0) printf("No carry operation.\n");
		else if( carry == 1) printf("1 carry operation.\n");
		else printf("%d carry operations.\n", carry);
	}
	return 0;
}