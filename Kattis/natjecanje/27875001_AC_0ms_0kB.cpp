#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int N, S, R;
	cin >> N >> S >> R;
	int kayak[16] = {0};
	
	int rusak;
	for(int i = 0; i < S; i++){
		cin >> rusak;
		kayak[rusak] -= 1;
	}
	
	int rev;
	for(int i = 0; i < R; i++){
		cin >> rev;
		kayak[rev] += 1;
	}
	
	int cou = 0;
	for(int i = 1; i <= N; i++){
//		cout << kayak[i] << " ";
		if(i == 1){
			if(kayak[i] == -1){
				if(kayak[i+1] == 1){
					kayak[i+1]--;
					kayak[i]++;
				}
				else{
					cou++;
				}
			}	
		}
		else if(i == N){
			if(kayak[i] == -1){
				if(kayak[i-1] == 1){
					kayak[i-1]--;
					kayak[i]++;
				}
				else{
					cou++;
				}
			}	
		}
		else{
			if(kayak[i] == -1){
				if(kayak[i-1] == 1){
					kayak[i-1]--;
					kayak[i]++;
				}
				else if(kayak[i+1] == 1){
					kayak[i+1]--;
					kayak[i]++;
				}
				else{
					cou++;
				}
			}
		}
		
	}
	cout << cou << endl;
	
	return 0;
}