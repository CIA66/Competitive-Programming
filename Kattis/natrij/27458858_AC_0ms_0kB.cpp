#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main(){
	
	int h1, s1, ms1;
	int h2, s2, ms2;
	int h = 0, s = 0, ms = 0;
	
	scanf("%d:%d:%d", &h1, &s1, &ms1);
	scanf("%d:%d:%d", &h2, &s2, &ms2);
	
	
	if(h1 == h2){
		if(s1 == s2){
			if(ms1 == ms2){
				h = 24; s = 0; ms = 0;
			}
			else{
				if(ms1 <= ms2){
					h = 0; s = 0; ms = ms2 - ms1;
				}
				else{
					h = 23; s = 59; ms = (60 - ms1) + ms2;
				}
			}
		}
		else{
			if(s1 <= s2){
				h = 0; s = s2 - s1;
			}
			else{
				h = 23; s = (60 - s1) + s2;
			}
			
			if(ms1 <= ms2){
				ms = ms2 - ms1;
			}
			else{
				ms = (60 - ms1) + ms2;
				if(s == 0){
					s = 60-1;
					h -= 1;	
				}
				else s -= 1;
			}
		}
	}
	else{
		if(h1 <= h2){
			if(s1 <= s2){
				h = h2 - h1; s = s2 - s1;
				if(ms1 <= ms2){
					ms = ms2 - ms1;
				}
				else{
					ms = (60 - ms1) + ms2;
					if(s == 0){
						s = 60 - 1;
						h -= 1;
					}
					else s -= 1;
				}
			}
			else{
				h = h2 - h1 - 1; s = (60 - s1) + s2;
				if(ms1 <= ms2){
					ms = ms2 - ms1;
				}
				else{
					s -= 1; ms = (60 - ms1) + ms2;
				}
			}
		}
		else{
//				printf("test1\n");
			h = (24 - h1) + h2;
			if(s1 <= s2){
				s = s2 - s1;
				if(ms1 <= ms2){
					ms = ms2 - ms1;
				}
				else{
					ms = (60 - ms1) + ms2;
					if(s == 0){
						s = 60-1;
						h -= 1;	
					}
					else s -= 1;
				}
			}
			else{
				h -= 1; s = (60 - s1) + s2;
				if(ms1 <= ms2){
					ms = ms2 - ms1;
				}
				else{
					ms = (60 - ms1) + ms2;
					if(s == 0){
						s = 60-1;
						h -= 1;	
					}
					else s -= 1;
				}
			}
		}
	}
		
	printf("%.2d:%.2d:%.2d\n", h, s, ms);
	
	return 0;
}