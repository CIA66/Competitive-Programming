#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	
	int S, X;
	scanf("%d %d", &S, &X);
	
	int cou = 0;
	while(S > 0){
		cou++;
		S /= X;
	}
	
	printf("%d\n", cou);
	
	return 0;
}