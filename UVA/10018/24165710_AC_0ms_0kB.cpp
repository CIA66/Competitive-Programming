#include<stdio.h>
#include<string.h>

#define ll long long

int isPalindrome(char str[], int len){
	
	for(int i = 0, k = len-1; i < len/2; i++, k--){
		if(str[i] != str[k]){
			return 0;
		}
	}
	
	return 1;
}

const char *rev(char str[], int len){
	char temp;
	for(int i = 0, k = len-1; i < len/2; i++, k--){
		temp = str[i];
		str[i] = str[k];
		str[k] = temp;
	}
	return str;
}

ll revese(ll num){
	
	ll hasil = 0;
	
	while(num != 0){
		
		hasil = hasil * 10 + (num % 10);
		num /= 10;
	}
	return hasil;
}

int main(){
	
	int N;
	scanf("%d", &N);
	
	ll num, num2, sum, count, len;
	char str[16];
	
	while(N--){
		count = 1;	
		scanf("%lld", &num); 
		
		while(1){
			num2 = revese(num);
			sum = num + num2;
			
			sprintf(str, "%lld", sum);
			len = strlen(str);
			if(isPalindrome(str, len)){
				printf("%d ", count);
				printf("%s\n", str);
				break;
			}
			num = sum;
			count++;
			
		}
		
	}
	
	
	return 0;
}
/*

 4294967295
3
195
265
750
 
*/