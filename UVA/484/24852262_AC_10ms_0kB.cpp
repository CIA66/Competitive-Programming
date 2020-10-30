#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 100000000

vector<pair<int, int> > arr;

int binser(int l, int r, int x){
	if(r >= l){
		int mid = l + (r - l) / 2;
		if(arr[mid].first == x) {
			arr[mid].second++;
			return mid;
		}
		if(arr[mid].first > x) return binser(l, mid-1, x);
		return binser(mid+1, r, x);
	}
	return inf;
}

int main(){

	int num, N = 0;
	while(scanf("%d", &num) != EOF){
		bool found = false;
		for(int i = 0; i < N; i++){
			if(arr[i].first == num){
				arr[i].second++;
				found = true;
				break;
			}
		}
		if(!found){
			N++;
			arr.push_back( make_pair(num, 1) );
		}
	}
	for(int i = 0; i < (int)arr.size(); i++){
		printf("%d %d\n", arr[i].first, arr[i].second);
	}
	
	return 0;
}

/*

3 1 2 2 1 3 5 3 3 2

*/