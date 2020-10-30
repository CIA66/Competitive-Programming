#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second

int main(){
	
	int n;
	scanf("%d", &n);
	
	char s[200006], t[200006];
	
	scanf("%s", s);
	scanf("%s", t);
	
//	vector < pair <int, int> > ans;
	
	vector < int > ab;
	vector < int > ba;
	
	for(int i = 0; i < n; i++){
		if(s[i] != t[i]){
			if(s[i] == 'a'){
				ab.push_back(i+1);
			}
			else{
				ba.push_back(i+1);
			}
		}
	}
	int fir, sec;
	
	if( (ab.size() + ba.size()) % 2 == 1){
		printf("-1\n");
	}
	else{
		if(ab.size() %2 == 1){
			printf("%d\n", (ab.size() + ba.size()) / 2 + 1);
		}
		else{
			printf("%d\n", (ab.size() + ba.size()) / 2);
		}
		while(ab.size() > 1){
			fir = ab.back();
			ab.pop_back();
			sec = ab.back();
			ab.pop_back();
			printf("%d %d\n", fir, sec);
		}
		while(ba.size() > 1){
			fir = ba.back();
			ba.pop_back();
			sec = ba.back();
			ba.pop_back();
			printf("%d %d\n", fir, sec);
		}
		
//		printf("ab : %d\n", ab.back());
//		printf("ba : %d\n", ba.back());
		if(ab.size() > 0){
			
			printf("%d %d\n", ab.back(), ab.back());
			printf("%d %d\n", ab.back(), ba.back());
		}
	}
	return 0;
}