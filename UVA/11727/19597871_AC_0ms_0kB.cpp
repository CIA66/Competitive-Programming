#include<stdio.h>

int main(){
	int T = 0;
	int yi = 0, er = 0, san = 0;
	int max = 0;
	int min = 0;
	scanf("%d", &T);
	for(int a=1; a<=T; a++){
		scanf("%d %d %d", &yi, &er, &san);
		printf("Case %d: ", a);
		if((yi > er && yi < san) || (yi > san && yi < er)) printf("%d\n", yi);
		else if((er > yi && er < san) || (er > san && er < yi)) printf("%d\n", er);
		else if((san > yi && san < er) || (san > er && san < yi)) printf("%d\n", san);
	}
	return 0;
}