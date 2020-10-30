#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second

typedef pair<int, int> pi; 

int main(){
	
	int N, T;
	cin >> N >> T;
	
	int c, t;
	
//	priority_queue <pair<int, int> > pq;
	priority_queue <pi, vector<pi>, greater<pi> > pq;
	for(int i = 0; i < N; i++){
		cin >> c >> t;
		pq.push(make_pair(-c, t));
	}
	
	int total_time = 0, total_c = 0;
	vector<int> vec(T);
	
	
	for(int i = 0; i < N; i++){
		
		pair<int, int> top = pq.top();
		
//		cout << -top.fi << " " << top.se << endl;
//		cout << "Now: " << now << endl;

		int j = top.se;
//		printf("\n\n-- i: %d\n", i);
		while(j >= 0){
			if(vec[j] == 0){
				vec[j] = -top.fi;
				break;
			}
			j--;
		}
		
//		printf("size:\n");
//        for(int q = 0; q < vec.size(); q++){
//        	printf("%d ", vec[q]);
//		}
//		printf("\n");
		
		pq.pop();
	}
	
	for(int i = 0; i < vec.size(); i++){
		total_c += vec[i];
	}
	
	
	cout << total_c << endl;
	
	return 0;
}