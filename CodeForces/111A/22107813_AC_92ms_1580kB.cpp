#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	
	
	ll n , x, y;
	
	cin >> n >> x >> y;
	
	ll kali = 0;
	
	vector < ll > ans;
	
	int valid = 1;
	if(n > y) valid = 0;
	while(n > 0 && valid){
		if(kali >= x){
			ans.push_back(1);
		}
		else {
			ll temp = y - (n - 1);
			y -= temp;
			kali += (temp * temp);
			ans.push_back(temp);
		}
		n--;
	}
	
	if(kali < x || !valid) printf("-1\n");
	else {
		for(ll i = 0; i < ans.size(); i++){
			cout << ans[i] << '\n';
		}
	}
	return 0;
}