#include<bits/stdc++.h>
using namespace std;

// 2,147,483,648

int main(){
	
	int n;
	scanf("%d", &n);
	
	int a, b, c;
	int count = 0; 
	for(int i = 0; i < n; i++){
		int temp = 0;
		scanf("%d %d %d", &a, &b, &c);
		if(a == 1) temp++;
		if(b == 1) temp++;
		if(c == 1) temp++;
		if(temp > 1) count++;
	}
	printf("%d\n", count);
	
	return 0;
}