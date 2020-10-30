#include<bits/stdc++.h>

using namespace std;

double gramTOcalori(double gram, int jenis){
	
	if(jenis == 0) return (gram*9);
	else if(jenis == 1 || jenis == 2 || jenis == 3) return (gram*4);
	else if(jenis == 4) return (gram*7);
}

std::pair<double,double> findCalItem(double num[], char food[]){
	
	double calItem, calFat;
	double calori[10], persen = 0;
	for(int i = 0; i < 5; i++){
		char now = food[i];
		if(now == '%'){
			persen += num[i];
		}
		else if(now == 'C'){
			calori[i] = num[i]; 
			calItem += calori[i];
		} 
		else if(now == 'g'){
			calori[i] = gramTOcalori(num[i], i);
			calItem += gramTOcalori(num[i], i);
		}
	}
	double one = calItem / (100 - persen);
	for(int j = 0; j < 5; j++){
		if(food[j] == '%'){
			calori[j] = num[j] * one;
			calItem += calori[j];
		}
	}
	
	return std::make_pair(calori[0], calItem);
}

int main(){

//	double qqqq = 31.03448275862069;
//	printf("%.0lf\n", round(qqqq));
	
	while(1){
		
		char str[106] = {""};
		
		double num[10] = {0};
		char food[10] = {""};
		
		double totalCal = 0, totalCalFat = 0;
		
		int item = 1;
		scanf("%[^\n]", str); getchar();
		if(strcmp(str, "-") == 0) break;
		
		sscanf(str, "%lf%c %lf%c %lf%c %lf%c %lf%c", &num[0], &food[0], &num[1], &food[1], &num[2], &food[2], &num[3], &food[3], &num[4], &food[4]);
//		printf("%lf %c - %lf %c - %lf %c - %lf %c - %lf %c\n", num[0], food[0], num[1], food[1], num[2], food[2], num[3], food[3], num[4], food[4]);
		
		pair<double, double> Calori = findCalItem(num, food);
		totalCalFat += Calori.first;
		totalCal += Calori.second;
		
//		printf("%lf %lf\n", totalCalFat, totalCal);
		// di setiap item harus simpen jumlah calori per item dan calori fatnya.
	
		while(1){
			scanf("%[^\n]", str); getchar();
			if(strcmp(str, "-") == 0) break;
			sscanf(str, "%lf%c %lf%c %lf%c %lf%c %lf%c", &num[0], &food[0], &num[1], &food[1], &num[2], &food[2], &num[3], &food[3], &num[4], &food[4]);
//			printf("%lf %c - %lf %c - %lf %c - %lf %c - %lf %c\n", num[0], food[0], num[1], food[1], num[2], food[2], num[3], food[3], num[4], food[4]);
			
			item++;
			pair<double, double> Calori = findCalItem(num, food);
			totalCalFat += Calori.first;
			totalCal += Calori.second;
//			printf("%lf %lf\n", totalCalFat, totalCal);
		}  

		double ans = (totalCalFat/totalCal*100);
		if(ans > 100){
			int tem = 100-ans;
			printf("%.0f%\n", ans-tem);
		}
		else{
			printf("%.0f%\n", ans);
		}
		
	}
	return 0;
}