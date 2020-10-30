#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	
	int I;
	while(1){
		scanf("%d", &I);
		if(I == 0) break;
		bitset<32> bset(I);
		string str = bset.to_string();
		char B[36]; int idx = 0;
		for(int i = 0; i < str.length(); i++){
			if(str[i] == '1'){
				for(int k = i; k < str.length(); k++){
					B[idx++] = str[k];
				}
				B[idx] = '\0';
				break;
			}
		}
//		cout << str << endl;
		int count = bset.count();
		printf("The parity of %s is %d (mod 2).\n", B, count);
//		cout << "The parity of " << bset << " is " << count << " (mod 2).\n" ;
	}
	return 0;
}