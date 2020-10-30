#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	
	int n;
	scanf("%d", &n);
	
	int pyBefore = 0, pylon = 0, energy = 0, dollars = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &pylon);
		energy = energy + (pyBefore - pylon);
		if(energy < 0){
			dollars += (0 - energy);
			energy = 0;
		}
		pyBefore = pylon;
	}
	printf("%d\n", dollars);
	
	
	return 0;
}
