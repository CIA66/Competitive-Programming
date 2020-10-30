#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	
	int n;
	
	cin >> n;
	
	ll prev , now;
	vector < ll > sub;
	
	ll count = 1;
	cin >> prev;
	
	for(int i = 1; i < n; i++){
		cin >> now;
		
		if(now == prev){
			count++;
		}
		else {
			if(count > 1){
				sub.push_back(count);
			}
			count = 1;
			prev = now;
		}
	}
	
	if(count > 1){
		sub.push_back(count);
	}
	count = 1;
	prev = now;
	
	ll sum = n;
	for(int i = 0; i < sub.size(); i++){
		sum += (sub[i] * (sub[i]-1)) / 2;
	}
	cout << sum << '\n';
	return 0;
}