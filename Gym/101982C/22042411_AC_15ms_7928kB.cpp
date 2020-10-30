#include <bits/stdc++.h>

using namespace std;

long long n, k, a[1005], arr[1005], dp[1005][1005], ans1 = 0, ans2 = 0, mod =  998244353, idx = 1, temp, cnt = 1;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 2; i <= n; i++) {
		if(a[i] != a[i-1]) {
			arr[idx] = cnt;
			cnt = 1;
			idx++;
		}
		else {
			cnt++;
		}
	}
	arr[idx] = cnt;
	dp[0][0] = 1;
	for(long long i=1; i<=n; i++){
		dp[i][0] = 1;
	    for(long long j=1; j<=i && j<=k; j++){
	        dp[i][j] = (dp[i-1][j] + (dp[i-1][j-1] * arr[i]) % mod ) % mod;
	    }
	}
	for(long long i=1; i<=k; i++) {
		ans1 += dp[n][i];
		ans1 %= mod;
	}
	
	k--;
	dp[0][0] = 1;
	for(long long i=1; i<=n; i++){
		dp[i][0] = 1;
	    for(long long j=1; j<=i && j<=k; j++){
	        dp[i][j] = (dp[i-1][j] + (dp[i-1][j-1] * arr[i]) % mod ) % mod;
	    }
	}
	for(long long i=1; i<=k; i++) {
		ans2 += dp[n][i];
		ans2 %= mod;
	}
	
	cout << (ans1 - ans2) % mod << endl;
}