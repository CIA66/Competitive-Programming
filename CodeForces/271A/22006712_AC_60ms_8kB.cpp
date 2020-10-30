#include<bits/stdc++.h>

using namespace std;

int disti(int x){
	char one, two, three, four;
	one = x % 10;
	x /= 10;
	two = x % 10;
	x /= 10;
	three = x % 10;
	x /= 10;
	four = x % 10;
	x /= 10;
	
	if(one == two || one == three || one == four || two == three || two == four || three == four){
		return 0;
	}
	return 1;
}

int main(){
	
	
	int y;
	scanf("%d", &y);
	
	int year = y+1;
	while(1){
		if(disti(year)){
			printf("%d\n", year);
			break;
		}
		year++;
	}
	
	return 0;
}