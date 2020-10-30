#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	
	int T;
	scanf("%d", &T);
	int sum = 0;
	for(int i = 0; i < T; i++){
		char str[16];
		scanf("%s", &str);
		if(strcmp(str, "donate") == 0){
			int d;
			cin >> d;
			sum += d;
		}
		else cout << sum << '\n';
	}
	return 0;
}