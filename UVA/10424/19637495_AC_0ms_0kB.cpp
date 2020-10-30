#include<stdio.h>
#include<string.h>

char toLower(char x){
	x = x - 'A' + 'a';
	return x;
}

int final(int num){
	if(num < 10) return num;
	
	int toSum = num % 10;
	int total = toSum;
	num = num / 10;
	
	while(num > 0){
		toSum = num % 10;
		total += toSum;
		num /= 10;
	}
	if(total > 9) return final(total);
	return total;
}

int main(){
//	printf("%d\n", toLower('Z') - 'a' + 1);

//	for(int a=0; a<200; a++){
//		printf("%c %d\n", a, a);
//	}

	char firstName[30];
	char secondName[30];
	strcpy(firstName, "");
	strcpy(secondName, "");
	
	while(gets(firstName)){
		gets(secondName);
		int len1 = 0, len2 = 0;
		len1 = strlen(firstName);
		len2 = strlen(secondName);
		int sum1 = 0, sum2 = 0;
		for(int a=0; a<len1; a++){
			if('A' <= firstName[a] && firstName[a] <= 'Z' || 'a' <= firstName[a] && firstName[a] <= 'z'){
				if('A'<= firstName[a] && firstName[a] <= 'Z'){
					firstName[a] = toLower(firstName[a]);
				}
				sum1 += (firstName[a] - 'a' + 1);
			}
		}
		for(int b=0; b<len2; b++){
			if(('A' <= secondName[b] && secondName[b] <= 'Z') || ('a' <= secondName[b] && secondName[b] <= 'z')){
//				printf("%c\n", secondName[b]);
				if('A' <= secondName[b] && secondName[b] <= 'Z'){
					secondName[b] = toLower(secondName[b]);
				}
//				printf("%c   ", secondName[b]);
				sum2 += (secondName[b] - 'a' + 1);
//				printf("sum2: %d\n", sum2);
			} else {
				sum2 += 0;
			}
		}
//		printf("%d %d\n", sum1, sum2);
		double result = 0.0;
		sum1 = final(sum1);
		sum2 = final(sum2);
//		printf("%d %d\n", sum1, sum2);
		
		if(sum1 < sum2){
			result = (double)sum1 / sum2 * 100;
		} else {
			result = (double)sum2 / sum1 * 100;
		}
		printf("%.2lf %%\n", result);
		
		strcpy(firstName, "");
		strcpy(secondName, "");
	}
	return 0;
}