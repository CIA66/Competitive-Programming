#include<stdio.h>
#include<string.h>

int main(){
	
	int tc = 1;
	while(1){
		int n, p;
		char ansName[86];
		int ansMax = 0;
		float ansPrice;
	
		scanf("%d %d", &n, &p); 
		if(n == 0 && p == 0) break;
		
		char name[1006][86];
		getchar();
		for(int i = 0; i < n; i++){
			scanf("%[^\n]", name[i]);
			getchar();
		}

		char proName[86];
		
		for(int x = 1; x <= p; x++){
			scanf("%[^\n]", proName);
			float d; int r;
			scanf("%f %d", &d, &r);
			
			//////
			if(r > ansMax){
				ansMax = r;
				ansPrice = d;
				strcpy(ansName, proName);
			}
			else if(r == ansMax){
				if(d < ansPrice){
					ansPrice = d;
					strcpy(ansName, proName);
				}
			}
			//////
			
			getchar();
			char reqName[1006][86];
			for(int j = 0; j < r; j++){
				scanf("%[^\n]", reqName[j]);
				getchar();
			}
			
		}
		
		if(tc != 1) printf("\n");
		printf("RFP #%d\n%s\n", tc++, ansName);
	}
	
	return 0;
}

/*

6 4
engine
brakes
tires
ashtray
vinyl roof
trip computer
Chevrolet
20000.00 3
engine
tires
brakes
Cadillac
70000.00 4
ashtray
vinyl roof
trip computer
engine
Hyundai
10000.00 3
engine
tires
ashtray
Lada
6000.00 1
tires
1 1
coffee
Starbucks
1.50 1
coffee
0 0

*/