
#include<bits/stdc++.h>

using namespace std;

#define ll long long 


int main(){
	
	int Y, W;
	scanf("%d %d", &Y, &W);
	
	int maxi;
	if(Y > W){
		maxi = Y;
	}
	else{
		maxi = W;
	}
	
	if(maxi == 6){
		printf("1/6");
	}	
	else if(maxi == 5){
		printf("1/3");
	}
	else if(maxi == 4){
		printf("1/2");
	}
	else if(maxi == 3){
		printf("2/3");
	}
	else if(maxi == 2){
		printf("5/6");
	}
	else if(maxi == 1){
		printf("1/1");
	}
	printf("\n");
	
	return 0;
}