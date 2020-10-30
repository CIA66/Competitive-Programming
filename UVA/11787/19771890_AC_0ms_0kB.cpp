#include<stdio.h>
#include<string.h>

int getNilai(char X){
	if(X == 'B') return 1;
	else if(X == 'U') return 10;
	else if(X == 'S') return 100;
	else if(X == 'P') return 1000;
	else if(X == 'F') return 10000;
	else if(X == 'T') return 100000;
	else if(X == 'M') return 1000000;
	return 0;
}

int main(){
	int T = 0;
	scanf("%d", &T); getchar();
	char str[506];
	for(int a=0; a<T; a++){
		gets(str);
		int len = strlen(str);
		int sum = 0;
		int netral = 0, naik = 0, turun = 0, valid = 1;
		int count = 1;
		for(int b=0; b<len; b++){
			if(netral == 0){
				netral = getNilai(str[b]);
			}
			else if(getNilai(str[b]) > netral){
				if(turun == 1) valid = 0;
				else {
					naik = 1;
					netral = getNilai(str[b]);
				}
				count = 1;
			}
			else if(getNilai(str[b]) < netral){
				if(naik == 1) valid = 0;
				else {
					turun = 1;
					netral = getNilai(str[b]);
				}
				count = 1;
			}
			else {
				count++;
			}
			if(count > 9) valid = 0;
			if(!valid) break;
			sum += getNilai(str[b]);
		}
		if(!valid) printf("error\n");
		else printf("%d\n", sum);
	}
	return 0;
}