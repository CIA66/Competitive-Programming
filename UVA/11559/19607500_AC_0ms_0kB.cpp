#include<stdio.h>

int main(){
	int participant = 0, budget = 0, hotel = 0, week = 0;
	int price = 0;
	int bed = 0;
	
	while(scanf("%d %d %d %d", &participant, &budget, &hotel, &week) != EOF){
		int valid = 0, cost = 0;
		for(int a=0; a<hotel; a++){
			scanf("%d", &price);
			valid = 0;
			int tempCost = 0;
			
			for(int b=0; b<week; b++){
				scanf("%d", &bed);
				if(bed >= participant) valid++;
			}
			
			if(valid > 0){
				tempCost = price * participant;
				if(cost == 0) cost = tempCost;
				else if(tempCost < cost) cost = tempCost;
			}
		}
		
		if(valid == 0 || cost > budget) printf("stay home\n");
		else printf("%d\n", cost);
	}	
	return 0;
}