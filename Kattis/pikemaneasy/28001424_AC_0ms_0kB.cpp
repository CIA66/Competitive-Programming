#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll N, T, A, B, C;
vector <ll> t;

int main(){
	
	ll temp;
	cin >> N >> T;
	cin >> A >> B >> C >> temp;
	t.push_back(temp);
	
	for(ll i = 1; i <= N-1; i++){
		temp = (((A * t[i-1] + B) % C) + 1);
		t.push_back(temp);
	}
	
	sort(t.begin(), t.end());
	
//	for(ll i = 0; i < N; i++){
//		cout << t[i] << " ";
//	}
//	cout << "\n";
	
	ll cou = 0, min_p = 0, p_sekarang = 0;
	
	for(ll i = 0; i < N; i++){
//		cout << t[i] << " ";
		if(p_sekarang + t[i] <= T){
			cou++;
			min_p = (min_p + t[i] + p_sekarang) % 1000000007;
			p_sekarang += t[i];
//			total = ((total % 1000000007) + ((t[i] % 1000000007) + (total % 1000000007)) %  1000000007) %  1000000007;
		}
		else{
			break;
		}
	}
	cout << cou << " " << min_p << endl;

	
	return 0;
}