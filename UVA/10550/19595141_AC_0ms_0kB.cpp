#include<stdio.h>

int main(){
	int start = 0;
	int c1 = 0, c2 = 0, c3 = 0;
	int toOpen = 0;
	int temp1 = 0, temp2 = 0, temp3 = 0;
	while(1){
		toOpen = 0;
		scanf("%d %d %d %d", &start, &c1, &c2, &c3);
		if(start == 0 && c1 == 0 && c2 == 0 && c3 == 0) break;
		
		toOpen = toOpen + 720;
		
		temp1 = c1 - start;
		if(temp1 < 0) {
			temp1 = temp1 * -1;
			temp1 = temp1 * 9;
		} else if (temp1 >= 0){
			temp1 = 360 - (temp1 * 9);
		}
//		printf("temp1 : %d\n", temp1);
		toOpen = toOpen + temp1;

		toOpen = toOpen + 360;
		
		temp2 = c2 - c1;
		if(temp2 < 0){
			temp2 = temp2 * -1;
			temp2 = 360 - (temp2 * 9);
		} else if (temp2 >= 0){ 
			temp2 = temp2 * 9;
		}
//		printf("temp2 : %d\n", temp2);
		toOpen = toOpen + temp2;
				
		temp3 = c3 - c2;
		if(temp3 < 0){
			temp3 = temp3 * -1;
			temp3 = temp3 * 9;
		} else if (temp3 >= 0){
			temp3 = 360 - (temp3 * 9);
		}
//		printf("temp3 : %d\n", temp3);
		toOpen = toOpen + temp3;
		
		printf("%d\n", toOpen);
	}
	return 0;
}