#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	
	ll N, x, maxi = 0;
	cin >> N;
	
	priority_queue<ll> pq;
	for(int i = 1; i <= N; i++){
		cin >> x;
		pq.push(x);
	}
	
	for(int i = 1; i <= N; i++){
		x = pq.top();
		if((i + x) > maxi){
			maxi = (i + x);
		}
		pq.pop();
	}
	cout << (maxi+1) << endl;
	
	return 0;
}