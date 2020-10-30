#include <bits/stdc++.h>

using namespace std;

bool used[200000010];
vector<int> arr; 
int a, m, i, cnt, ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin>>a>>m;
	arr.push_back(a);
	used[a] = 1;
	i = 1;
	while(used[i]) {
		i++;
	}
	cnt = 0;
	while(true){
		if(used[m]) {
			ans = cnt;
			break;
		}
		cnt++;
		used[i] = 1;
		int temp = arr.back() + i;
		used[temp] = 1;
		for(int j = 0; j < arr.size(); j++) {
			used[temp - arr[j]] = 1;
		}
		arr.push_back(temp);
		while(used[i]) {
			i++;
		}
	}
	cout<<ans+1<<endl;
 	
}