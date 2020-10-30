#include <bits/stdc++.h>

using namespace std;

int n, sz, cnt = 0;
bool prime[1000005];
vector<int> p;

void sieve(int n) {
	memset(prime, true, sizeof(prime));
	for(int i = 2; i * i <= n; i++) {
		if(prime[i]) {
			for(int j = i * i; j <= n; j = j + i) {
				prime[j] = false;
			}
		}
	}
	for(int i = 2; i <= 1000000; i++) {
		if(prime[i]) {
			p.push_back(i);
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	sieve(1000000);
	sz = p.size();
	cin >> n;
	while(n >= 4) {
		cnt++;
		for(int i = 0; i < sz; i++) {
			if(prime[n - p[i]]) {
				n = (n - p[i]) - p[i];
				break;
			}
		}
	}
	cout << cnt << endl;
}