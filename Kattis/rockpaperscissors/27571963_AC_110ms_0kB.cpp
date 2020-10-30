#include<bits/stdc++.h>

using namespace std;


int main(){
	
	int n, k;
	int fl = 0;
	while(1){
		
		scanf("%d", &n);
		if(n == 0) break;
		
		scanf("%d", &k);
		
		int p1, p2;
		char m1[106], m2[106];
		int len = k*n*(n - 1) / 2;
		int won[106] = {0};
		int lost[106] = {0};
		for(int i = 0; i < len; i++){
			scanf("%d %s %d %s", &p1, m1, &p2, m2);
			if(m1[0] == 'r' && m2[0] == 'p'){
				lost[p1]++; won[p2]++;
			}
			else if(m1[0] == 'r' && m2[0] == 's'){
				won[p1]++; lost[p2]++;
			}
			else if(m1[0] == 'p' && m2[0] == 'r'){
				won[p1]++; lost[p2]++;
			}
			else if(m1[0] == 'p' && m2[0] == 's'){
				lost[p1]++; won[p2]++;
			}
			else if(m1[0] == 's' && m2[0] == 'r'){
				lost[p1]++; won[p2]++;
			}
			else if(m1[0] == 's' && m2[0] == 'p'){
				won[p1]++; lost[p2]++;
			}
		}
		
		if(fl == 0){
			fl = 1;
		}
		else if(fl == 1){
			printf("\n");
		}
		for(int p = 1; p <= n; p++){
			
			if(won[p] == 0 && lost[p] == 0){
				printf("-\n");
			}
			else{
				double ans = double(won[p]) / (double(won[p]) + double(lost[p]));
				printf("%.3lf\n", ans);
			}
		}
	}
	return 0;
}