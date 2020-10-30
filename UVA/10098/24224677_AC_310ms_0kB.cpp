#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
	
	int N;
	scanf("%d", &N); getchar();
	string str;
	while(N--){
		cin >> str;
		sort(str.begin(), str.end());
		do{
			cout << str << endl;
		}while( std::next_permutation(str.begin(), str.end()));
		printf("\n");
	}
	
	return 0;
}