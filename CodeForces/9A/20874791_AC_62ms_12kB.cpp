#include<stdio.h>

int maximum(int a, int b){
	if(a > b) return a;
	return b;
}

int main(){
	
	int Y, W;
	
	scanf("%d %d", &Y, &W);
	
	int max = maximum(Y, W);
	
	if(max == 6){
		printf("1/6\n");
	}
	else if(max == 5){
		printf("1/3\n");
	}
	else if(max == 4){
		printf("1/2\n");
	}
	else if(max == 3){
		printf("2/3\n");
	}
	else if(max == 2){
		printf("5/6\n");
	}
	else if(max == 1){
		printf("1/1\n");
	}
	
	return 0;
}