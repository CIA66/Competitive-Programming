#include<stdio.h>

int timeSum(int mm, int ss){
	return  (mm * 60) + ss;
}

int main(){
	
	int T;
	
	scanf("%d", &T);
	
	int sumH = 0, sumA = 0, timeH = 0, timeA = 0;
	int timebefore = 0;
	int win = 0, winH = 0, winA = 0;
	
	for(int i=0; i<T; i++){
		
		char T[6];
		int p;
		int mm, ss;
		
		scanf("%s %d %d:%d", T, &p, &mm, &ss);
		
		if(T[0] == 'H') sumH += p;
		else if(T[0] == 'A') sumA += p;
		
		if(sumH > sumA){
			if(win){
				if(winA){
					timeA += (timeSum(mm, ss) - timebefore);
				} else if(winH) {
					timeH += (timeSum(mm, ss) - timebefore);
				}
				
			}
			
			win = 1;
			winH = 1;
			winA = 0;

			
		} else if (sumA > sumH){
			if(win){
				if(winH){
					timeH += (timeSum(mm, ss) - timebefore);
				} else if(winA){
					timeA += (timeSum(mm, ss) - timebefore);
				}
				
			}
			
			win = 1;
			winA = 1;
			winH = 0;
			
		} else {
			if(winH){
				timeH += (timeSum(mm, ss) - timebefore);
			} else if(winA){
				timeA += (timeSum(mm, ss) - timebefore);
			}
			win = 0;
		}
		
		timebefore = timeSum(mm, ss);
		
//		printf("time before : %d:%d\n", timebefore/60, timebefore - (timebefore/60));
//		printf("sumH : %d -- sumA : %d\n", sumH, sumA);
//		printf("timeH : %d -- timeA : %d\n", timeH, timeA);
	}
	
	if(winH){
		timeH += (1920 - timebefore);
	} else if(winA){
		timeA += (1920 - timebefore);
	}
	
	if(sumH > sumA){
		printf("H ");
	} else {
		printf("A ");
	}
	
	int jam = timeH / 60;
	int menit = timeH - (jam*60);
	
	if(timeH < 600){
		printf("%.1d:%.2d ", jam, menit);
	} else {
		printf("%.2d:%.2d ", jam, menit);
	}
	
	jam = timeA / 60;
	menit = timeA - (jam*60);
	if(timeA < 600){
		printf("%.1d:%.2d\n", jam, menit);
	} else {
		printf("%.2d:%.2d\n", jam, menit);
	}
	return 0;
}