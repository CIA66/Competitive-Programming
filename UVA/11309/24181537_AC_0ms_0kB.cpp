#include<stdio.h>
#include<string.h>

int isPalindrome(char str[], int len){
	
	if(len == 0) return 1;
	if(len == 0) return 0;
	for(int i = 0, k = len-1; i < len/2; i++, k--){
		if(str[i] != str[k]){
			return 0;
		}
	}
	
	return 1;
}


int main(){
	
	int N;
	scanf("%d", &N);
	
	int HH, MM;
	char str[6];
	for(int i = 0; i < N; i++){
		scanf("%d:%d", &HH, &MM);
		
		char str1[6], str2[6]; int start = 1;
		while(1){
			sprintf(str1, "%d", HH);
			sprintf(str2, "%d", MM);
			
			int idx = 0;
//			printf("str1: %s  str2:%s\n", str1, str2);
			if(HH < 10){
	//			str[idx++] = '0';
				if(str1[0] != '0') str[idx++] = str1[0];
			}
			else{
				str[idx++] = str1[0];
				str[idx++] = str1[1];
			}
			
			if(MM < 10){
	//			str[idx++] = '0';
				if(idx != 0){
					str[idx++] = '0';
					str[idx++] = str2[0];
				}
				else{
					if(str2[0] != '0') str[idx++] = str2[0];
					
				}
			}
			else{
				str[idx++] = str2[0];
				str[idx++] = str2[1];
			}
			
			
			
			str[idx] = '\0';
			
//			printf("str : %s\n", str);
			if(isPalindrome(str, idx)){
				if(!start) break;
				else if(start){
					MM++;
					if(MM == 60){
						HH++;
						MM = 0;
					}
					if(HH == 24){
						HH = 0;
						MM = 0;
					}
				}
			}
			else{
				MM++;
				if(MM == 60){
					HH++;
					MM = 0;
				}
				if(HH == 24){
					HH = 0;
					MM = 0;
				}
			}
			start = 0;
		}
		
		printf("%.2d:%.2d\n", HH, MM);
	}
	return 0;
}

/*

3
00:00
23:30
14:59

*/