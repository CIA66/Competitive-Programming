#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll binarySearch(vector <ll> &v, ll x){
	ll low = 0, high = v.size()-1;
	while(low <= high){
		ll mid = (low + high) / 2;
		if(v[mid] <= x)
			low = mid + 1;
		else if(v[mid] > x && v[mid-1] <= x)
			return mid;
		else if(v[mid] > x && mid == 0)
			return mid;
		else
			high = mid - 1;
	}
	return -1;
}

ll bagiTiga(ll arr[], ll n){
	ll cou = 0;
	
	ll prefix[n];
	prefix[0] = arr[0];
	for(ll i = 1; i < n; i++){
		prefix[i] = prefix[i-1] + arr[i];
	}
	
	ll totalSum = prefix[n-1];
	
	if(totalSum % 3 != 0){
		return 0;   // Klo sum semua angka gk bisa dibagi 3 berarti zonk
	}
	
	ll suffix[n];
	suffix[n-1]= arr[n-1];
	for(ll i = n-2; i >= 0; i--){
		suffix[i] = suffix[i+1] + arr[i];
	}
	
	vector <ll> v;
	for(ll i = 0; i < n; i++){
		if(suffix[i] == totalSum / 3){
			v.push_back(i);
		}
	}
	
	for(ll i = 0; i < n; i++){
		if(prefix[i] == totalSum / 3){
			ll res = binarySearch(v, i+1);
			
			if(res != -1){
				cou += v.size() - res;
			}
		}
	}
	return cou;
}

ll n, arr[500006];
	
int main(){
	

	scanf("%lld", &n);
	for(ll i = 0; i < n; i++){
		scanf("%lld", &arr[i]);
	}
	
	ll cou = bagiTiga(arr, n);
	printf("%lld\n", cou);
	
	return 0;
}