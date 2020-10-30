#include<bits/stdc++.h>

using namespace std;

#define ll long long

int c(int x){
	int rev = 0;
	int tambah = 1;
	
	while(x != 0){
		int temp = x%10;
		if(temp == 4 || temp == 7){
			rev += (tambah * (temp));
			tambah *= 10;
		}
		
		x /= 10;
	}
	return rev;
}

int main(){
	
	int a, b;
//	while(1){
		scanf("%d %d", &a, &b);
		a++;
		while(c(a) != b){
			a++;
		}
		printf("%d\n", a);
//	}
	
	return 0;
}