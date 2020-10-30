#include<bits/stdc++.h>
using namespace std;
int main(){
	
	map<int, string> hp;

	hp['a'] = "2";
	hp['b'] = "22";
	hp['c'] = "222";
	hp['d'] = "3";
	hp['e'] = "33";
	hp['f'] = "333";
	hp['g'] = "4";
	hp['h'] = "44";
	hp['i'] = "444";
	hp['j'] = "5";
	hp['k'] = "55";
	hp['l'] = "555";
	hp['m'] = "6";
	hp['n'] = "66";
	hp['o'] = "666";
	hp['p'] = "7";
	hp['q'] = "77";
	hp['r'] = "777";
	hp['s'] = "7777";
	hp['t'] = "8";
	hp['u'] = "88";
	hp['v'] = "888";
	hp['w'] = "9";
	hp['x'] = "99";
	hp['y'] = "999";
	hp['z'] = "9999";
	hp[' '] = "0";

	
	int N;
	cin >> N; getchar();
	
	string str;
	for(int i = 1; i <= N; i++){
//		cin >> str;
		getline(cin, str);
		cout << "Case #" << i << ":";
		for(int j = 0; j < str.length(); j++){
			if(j == 0){
				cout << " " << hp[str[j]];
				continue;
			}
			
			if(hp[str[j]][0] == hp[str[j-1]][0])
				cout << " " << hp[str[j]];
			else 
				cout << hp[str[j]];
		}
		cout << '\n';
	}
	return 0;
}