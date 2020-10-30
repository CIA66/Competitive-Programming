#include<stdio.h>

int main(){
	int T = 0, N = 0;
	int res = 0;
	scanf("%d", &T);
	for(int a=1; a<=T; a++){
		scanf("%d", &N);
		
//		For each test case, output the answer to the following skill testing question on a line by itself: 
//		\“Multiply n by 567, then divide the result by 9, then add 7492, then multiply by 235, 
//		then divide by 47, then subtract 498. What is the digit in the tens column?”

		res = N * 567;
		res /= 9;
		res += 7492;
		res *= 235;
		res /= 47;
		res -= 498;
		
		res /= 10;
		res %= 10;
		if(res < 0) res *= -1;
		printf("%d\n", res);
	}
	return 0;
}