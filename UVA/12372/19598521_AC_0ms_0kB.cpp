#include<stdio.h>

int main(){
	int T = 0;
	int L = 0, W = 0, H = 0;
	scanf("%d", &T);
	for(int a=1; a<=T; a++){
		scanf("%d %d %d", &L, &W, &H);
		printf("Case %d: ", a);
		if(L <= 20 && W <= 20 && H <= 20)printf("good\n");
		else printf("bad\n");
	}
	return 0;
}