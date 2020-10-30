#include<stdio.h>


int main(){
	int brown = 0, green = 0, clear = 0;
	int bin1, bin2, bin3;
	int B1 = 0, G1 = 0, C1 = 0;
	int B2 = 0, G2 = 0, C2 = 0;
	int B3 = 0, G3 = 0, C3 = 0;
	
	while(scanf("%d %d %d %d %d %d %d %d %d", &B1, &G1, &C1, &B2, &G2, &C2, &B3, &G3, &C3) != EOF){
		brown = B1 + B2 + B3;
		green = G1 + G2 + G3;
		clear = C1 + C2 + C3;
		
//		BCG
		int now = (brown - B1) + (clear - C2) + (green - G3);
		int final = now;
		int list = 1;
//		BGC
		now = (brown - B1) + (green - G2) + (clear - C3);
		if(now < final){
			list = 2;
			final = now;
		}
//		CBG
		now = (clear - C1) + (brown - B2) + (green - G3);
		if(now < final){
			list = 3;
			final = now;
		}
//		CGB
		now = (clear - C1) + (green - G2) + (brown - B3);
		if(now < final){
			list = 4;
			final = now;
		}
//		GBC
		now = (green - G1) + (brown - B2) + (clear - C3);
		if(now < final){
			list = 5;
			final = now;
		}
//		GCB
		now = (green - G1) + (clear - C2) + (brown - B3);
		if(now < final){
			list = 6;
			final = now;
		}
		
		if(list == 1) printf("BCG %d\n", final);
		else if(list == 2) printf("BGC %d\n", final);
		else if(list == 3) printf("CBG %d\n", final);
		else if(list == 4) printf("CGB %d\n", final);
		else if(list == 5) printf("GBC %d\n", final);
		else if(list == 6) printf("GCB %d\n", final);
	}
	
	
	
	return 0;
}