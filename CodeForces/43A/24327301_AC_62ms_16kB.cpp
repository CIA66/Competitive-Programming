#include<bits/stdc++.h>

using namespace std;


int main(){
	
	int N;
	scanf("%d", &N); getchar();
	char name[16], A[16], B[16];
	int tim1 = 0, tim2 = 0;
	scanf("%s", A);
	tim1++;
	N--;
	while(N--){
		scanf("%s", name);
		if(strcmp(name, A) != 0){
			strcpy(B, name);
			tim2++;
		}
		else tim1++;
	}
	if(tim1 > tim2) printf("%s\n", A);
	else printf("%s\n", B);
	
	return 0;
}