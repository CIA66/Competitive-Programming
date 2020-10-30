#include<bits/stdc++.h>

using namespace std;

char month[][16] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main(){
	
	char str[16]; int curr = 0;
	scanf("%s", str); getchar();
	for(int i = 0; i < 12; i++){
//		printf("%s\n", month[i]);
		if(strcmp(str, month[i]) == 0) curr = i;
	}
	int k, x;
//	printf("%d\n", curr);
	scanf("%d", &k);
//	int i = 0;
//	while(k--){
//		curr++;
//		if(curr == 12) curr = 0;
//		printf("%d : %d\n", i++, curr);
//	}
	x = (curr + k) % 12;
	printf("%s\n", month[x]);
	
	
	return 0;
}