// G

#include<bits/stdc++.h>

using namespace std;



int main(){
	
	int T, B, C;
	scanf("%d", &T); getchar();
	while(T--){
		scanf("%d %d", &B, &C); getchar();
		char code[26];
		int arrYear, arrMonth, arrDay, arrHour, arrMin;

		int depYear, depMonth, depDay, depHour, depMin;
		int arr[100006] = {0}, dep[100006] = {0};
		int months[16] = {0, 44640, 84960, 129600, 172800, 217440, 260640, 305280, 349920, 393120, 437760, 480960};
		for(int i = 0; i < B; i++){
			scanf("%s %d-%d-%d %d:%d %d-%d-%d %d:%d", code, &arrYear, &arrMonth, &arrDay, &arrHour, &arrMin, &depYear, &depMonth, &depDay, &depHour, &depMin); getchar();
//			printf("%s %d-%d-%d %d:%d %d-%d-%d %d:%d\n",code, arrYear, arrMonth, arrDay, arrHour, arrMin, depYear, depMin, depDay, depHour, depMin);
			
			if(arrYear == 2016 && arrMonth > 2){
				arr[i] = (arrYear - 2013) * 525600 + months[arrMonth-1] + (arrDay-1) * 1440 + arrHour*60 + arrMin + 1440;
			}
			else{
				arr[i] = (arrYear - 2013) * 525600 + months[arrMonth-1] + (arrDay-1) * 1440 + arrHour*60 + arrMin;
			}
			
			if(depYear == 2016 && depMonth > 2){
				dep[i] = (depYear - 2013) * 525600 + months[depMonth-1] + (depDay-1) * 1440 + depHour*60 + depMin + 1440;
			}
			else{
				dep[i] = (depYear - 2013) * 525600 + months[depMonth-1] + (depDay-1) * 1440 + depHour*60 + depMin;
			}
		}
		sort(arr, arr+B);
		sort(dep, dep+B);
//		for(int q = 0; q < B; q++){
//			printf("%d\n", arr[q]);
//		}
//		for(int q = 0; q < B; q++){
//			printf("%d\n", dep[q]);
//		}
		int sum = 0;
		for(int j = 0, k = 0; j < B; j++){
			if((arr[j] - dep[k]) < C){
//			printf("---\n");
				sum++;
			}
			else{
				k++;
			}
		}
		printf("%d\n", sum);
	}
	
	return 0;
}