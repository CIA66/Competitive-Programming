#include<bits/stdc++.h>


int main(){
	
	int x;
	scanf("%d", &x);
	
	int sum = 0, step = 5;
	while(x != 0){
		sum += x / step;
		x = x % step;
		step--;
	}
	printf("%d\n", sum);
	
	return 0;
	
}