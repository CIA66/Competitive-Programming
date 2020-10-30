#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int m, n;
	cin >> m >> n;
	
	string word; int num;
	map<string, int> dictionary;
	while(m--){
		cin >> word >> num;
		dictionary[word] = num;
	}
	
	
	for(int i = 0; i < n; i++){
		string str;
		int total = 0;
		while(1){
			cin >> str;
			if(str == ".") break;
			total += dictionary[str];
		}
		printf("%d\n", total);
	}
	return 0;
}