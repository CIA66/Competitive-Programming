#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define inf 1000000

int main(){
	
	int N, budget, hotel, week;
	
	while(scanf("%d %d %d %d", &N, &budget, &hotel, &week) == 4){
		
		int mini = inf;
		int valid = 0;
		for(int i = 0; i < hotel; i++){
			int price, bed;
			scanf("%d", &price);
			for(int j = 0; j < week; j++){
				scanf("%d", &bed);
				if(bed >= N){
					int temp = N * price;
					if(temp < mini){
						mini = temp;
						valid = 1;
					}
				}
			}
		}
		if(valid && mini <= budget) printf("%d\n", mini);
		else printf("stay home\n");
	}
	return 0;
}