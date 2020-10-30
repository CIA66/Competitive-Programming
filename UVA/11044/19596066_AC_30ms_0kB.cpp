#include<stdio.h>

int main(){
	int t = 0, n = 0, m = 0;
	int count = 0;
	scanf("%d", &t);
	for(int a=0; a<t; a++){
		count = 0;
		scanf("%d %d", &n, &m);
		int row = 2;
		while(row < n){
			int col = 2;
			while(col < m){
				count++;
				col += 3;
			}
			row += 3;
		}
		printf("%d\n", count);
	}
	return 0;
}