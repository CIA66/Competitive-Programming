#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 288230376151711744
struct Data{
	ll tempatA, moveA, tempatB, moveB;
	ll totalMove;
};

int main(){
	
	
	while(1){
		ll A = 0, B = 0;
		scanf("%lld %lld", &A, &B);
		if(A == 0 && B == 0) break;
		ll Aa = A, Bb = B;
		int ketemu = 0;
		ll Sa = 0, Sb = 0, C = 0, now = 0;
		
		priority_queue <pair<ll, ll> > pqA;
		priority_queue <pair<ll, ll> > pqB;
		ll move = 0;
		
		while(1){
			pqA.push(make_pair(A, move));
			if(A == 1) break;
			if(A % 2 == 0){
				A /= 2;
			}
			else if(A % 2 == 1){
				A = A*3 + 1;
			}
			move++;
		}
		
		move = 0;
		while(1){
			pqB.push(make_pair(B, move));
			if(B == 1) break;
			if(B % 2 == 0){
				B /= 2;
			}
			else if(B % 2 == 1){
				B = B*3 + 1;
			}
			move++;
		}
		
		// top <letaknya, movenya brp>
		vector<Data> vec;
		while(1){
			pair<ll, ll> topA = pqA.top(); 
//			printf("A: %lld %lld\n", topA.first, topA.second);
			pair<ll, ll> topB = pqB.top(); 
//			printf("B: %lld %lld\n", topB.first, topB.second);
	
			if(topA.first == topB.first){
				Data temp;
				temp.moveA = topA.second;
				temp.moveB = topB.second;
				temp.tempatA = topA.first;
				temp.tempatB = topB.first;
				temp.totalMove = topA.second + topB.second;
				vec.push_back(temp);
				pqA.pop();
				pqB.pop();
			}
			else if(topA.first > topB.first){
				pqA.pop();
			}
			else{
				pqB.pop();
			}
			
			if(pqA.empty() || pqB.empty()) break;
		}
		
		ll mini = inf;
		for(int i = 0; i < vec.size(); i++){
			
//			printf("--- %lld %lld - %lld %lld  : %lld\n", vec[i].tempatA, vec[i].moveA, vec[i].tempatB, vec[i].moveB, vec[i].totalMove);
			if(vec[i].totalMove < mini){
				C = vec[i].tempatA;
				Sa = vec[i].moveA;
				Sb = vec[i].moveB;
				mini = vec[i].totalMove;
			}
		}
		
		printf("%lld needs %lld steps, %lld needs %lld steps, they meet at %lld\n", Aa, Sa, Bb, Sb, C);
	}
	return 0;
}