#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	
	int num[6];
	while(1){
		scanf("%d %d %d", &num[0], &num[1], &num[2]);
		if(num[0] == 0 && num[1] == 0 && num[2] == 0) break;
		
		sort(num, num+3);
		
		if((num[0]*num[0]) + (num[1]*num[1]) == (num[2]*num[2])) printf("right\n");
		else printf("wrong\n");
	}
	return 0;
}