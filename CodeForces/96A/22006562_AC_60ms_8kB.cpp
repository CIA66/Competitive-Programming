#include<bits/stdc++.h>


using namespace std;

int main(){
	
	char str[106];
	gets(str);
	int len = strlen(str);
	int teamZero = 0, teamOne = 0;
	
	int danger = 0;
	for(int i = 0; i < len; i++){
		if(str[i] == '0'){
			teamZero++;
			teamOne = 0;
			if(teamZero == 7){
				danger = 1;
				break;
			}
		}
		else{
			teamOne++;
			teamZero = 0;
			if(teamOne == 7){
				danger = 1;
				break;
			}
		}
	}
	
	if(danger) puts("YES");
	else puts("NO");
	return 0;
}