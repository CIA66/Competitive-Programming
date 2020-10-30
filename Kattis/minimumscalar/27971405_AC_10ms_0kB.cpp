#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	int T, N;
	priority_queue<ll> pq1;
	priority_queue<ll> pq2;
	
	cin >> T;
	int t = 1;
	while(T--){
		cin >> N;
		ll x;
		for(int i = 0; i < N; i++){
			cin >> x;
			pq1.push(x);
		}
		for(int i = 0; i < N; i++){
			cin >> x;
			pq2.push(-x);
		}
		
		ll hasil = 0;
		for(int i = 0; i < N; i++){
			hasil += (pq1.top() * -pq2.top());
			pq1.pop();
			pq2.pop();
		}
		cout << "Case #" << t++ << ": " << hasil << endl;
	}
	
	return 0;
}