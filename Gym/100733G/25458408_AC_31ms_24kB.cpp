#include<bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int MOD = 1e9+7;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

ofstream txtOut;

void solve() {
	string s; cin >> s;
	bool flag = false;
	for(int i = 0; i < s.length(); i++) {
		if(flag) {
			if(s[i] == '+') s[i] = '*';
			else if(s[i] == '*') s[i] = '+';
			else {
				if(islower(s[i])) s[i] = toupper(s[i]);
				else s[i] = tolower(s[i]);
			}
		}

		if(s[i] == '(' || s[i] == ')') continue;
		else if(s[i] == '[') {
			s[i] = '(';
			flag = !flag;
		}else if(s[i] == ']'){
			s[i] = ')';
			flag = !flag;
		}

	}

	cout << s << endl;
}

int main() {
	// txtOut.open("output.txt");

	int t = 1;
	// cin >> t;

	for(int i = 0; i < t; i++) {
		solve();
	}



	// txtOut.close();
	
	return 0;
}