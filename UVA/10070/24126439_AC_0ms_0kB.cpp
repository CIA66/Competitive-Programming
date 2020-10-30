#include<bits/stdc++.h>
using namespace std;

int mod(string num, int a){
	int res = 0;
	
	for(int i = 0; i < num.length(); i++){
		res = (res*10 + (int)num[i] - '0') % a;
	}
	
	return res;
}

int main(){
	int start = 1;
	string N;
	while(getline(cin, N)){
//		cout << N << endl;
		int count = 0, kabisat = 0;
		
		if(start == 1){
			start = 0;
		}
		else if(start == 0){
			printf("\n");
		}
		
		if(mod(N, 400) == 0){
			printf("This is leap year.\n");
			kabisat = 1;
			count++;
		}
		if((mod(N, 4) == 0) && (mod(N, 100) != 0)){
			printf("This is leap year.\n");
			kabisat = 1;
			count++;
		}
		if(mod(N, 15) == 0){
			printf("This is huluculu festival year.\n");
			count++;
		}
		if((mod(N, 55) == 0) && (kabisat == 1)) printf("This is bulukulu festival year.\n");
		if(count == 0) printf("This is an ordinary year.\n");
	}
	
	return 0;
}

/*

2000
3600
4515
2001

200000000000000000000000000000
23456789765432222224444444444444444
11111111111111111144444444444441111111111111
155555555555000000000000000000000
30000000000000000000000000000044444444444444444400000000000
100000000000000000000000000000000000000000000000000004444444444
444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
220000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

This is leap year.

This is leap year.

This is an ordinary year.

This is leap year.

This is leap year.
This is huluculu festival year.

This is leap year.

This is leap year.

This is leap year.
This is bulukulu festival year.


*/