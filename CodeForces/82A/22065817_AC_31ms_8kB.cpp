#include<bits/stdc++.h>


int main(){
//	while(1){
		
	int n;
	scanf("%d", &n);
	
	int awal = 1;
	int akhir = awal * 5;
	int i = -1, ans = 0;
	
	while(1){
		i++;
		if(awal <= n && n <= akhir){
//		printf("%d %d\n", awal, akhir);
			n -= (awal - 1);
//			printf("n : %d\n", n);
			int temp = 1, batas = (int)pow(2, (double)i);
			for(int j = 1; j <= 5; j++){
//				printf("temp: %d   bata : %d\n", temp, batas);
				if(temp <= n && n <= (batas)){
					ans = j;
					break;
				}
				temp = batas;
				batas = temp + (int)pow(2, (double)i);
//				printf("	%d\n", (int)pow(2, (double)i));
			}
			break;
		}
		
		awal = akhir;
		akhir = akhir*2 + 5;
		awal++;
		
	}
	
	if(ans == 1) printf("Sheldon\n");
	else if(ans == 2) printf("Leonard\n");
	else if(ans == 3) printf("Penny\n");
	else if(ans == 4) printf("Rajesh\n");
	else if(ans == 5) printf("Howard\n");
	
	return 0;
}