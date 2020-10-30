#include<stdio.h>


int main(){
	
	int k, m, c, r, course[106], now, i;
	while(1){
		int yes = 1;
		
		scanf("%d", &k);
		if(k == 0) break;
		
		int m;
		scanf("%d", &m);
		
		for(i = 0; i < k; i++){
			scanf("%d", &course[i]);
		}
		
		for(i = 0; i < m; i++){
			scanf("%d %d", &c, &r);
			
			int count = 0;
			for(int j = 0; j < c; j++){
				scanf("%d", &now);
				for(int xx = 0; xx < k; xx++){
					if(now == course[xx]){
						count++;
						break;
					}
				}
			}
//			printf("count : %d\n", count);
			if(count < r) yes = 0;
			
		}
		if(yes) printf("yes\n");
		else printf("no\n");
		
	}
	return 0;
}

/*

0


*/
