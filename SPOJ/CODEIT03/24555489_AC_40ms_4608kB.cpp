#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define inf 100000000

int main(){
	
	int t;
	scanf("%d", &t);
	
	char days[][16] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	
//	for(int i = 0; i < 20; i++){
//		printf("%s\n", days[(i%7)]);
//	}
	
	int date, month, year;
	while(t--){
		scanf("%d %d %d", &date, &month, &year);
		
		int dd = 11, mm = 1, yy = 2012, tgl = 2;
		while(1){
			if(dd == date && mm == month && yy == year){
				printf("%s\n", days[(tgl%7)]);
				break;
			}
			tgl++;
			dd++;
			if(mm == 2){
				if(yy % 4 == 0 && yy % 100 != 0){
					// 29
					if(dd == 30){
						dd = 1;
						mm++;
					}
				}
				else{
					// 28
					if(yy % 400 == 0){
						if(dd == 30){
							dd = 1;
							mm++;
						}
					}
					else if(dd == 29){
						dd = 1;
						mm++;
					}
				}
			}
			else if(mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12){
				// 31
				if(dd == 32){
					dd = 1;
					mm++;
				}
			}
			else if(mm == 4 || mm == 6 || mm == 9 || mm == 11){
				// 30
				if(dd == 31){
					dd = 1;
					mm++;
				}
			}
			
			if(mm == 13){
				mm = 1;
				dd = 1;
				yy++;
			}
			
		}
	}
	
	return 0;
}

/*
5
1 2 3 7 8
*/