#include<bits/stdc++.h>

using namespace std;

#define ll long long 


int toIn(char str[]){
	
	int len = strlen(str);
	int x = 1, sum = 0;
	for(int i = len-1; i >= 0; i--){
		if(str[i] == '1'){
//			printf("--%d\n", x);
			sum += x;
		}
		x *= 2;
	}
	return sum;
}

char str[1000100];

int main(){
	
//	while(1){
		
		int num;
		scanf("%s", str); 
		num = toIn(str);
		int len = strlen(str);
		int cou = 0;
		
		while(1){
			if(len == 1 && str[0] == '1') break;
//				printf("len : %d\n", len);
			if(str[len-1] == '1'){
				int deret = 1;
				for(int i = len-1; i >= 0; i--){
					if(str[i] == '0'){
						str[i] = '1';
						deret = 0;
						break;
					}
					else str[i] = '0';
				}
				if(deret){
//					printf("lenlen : %d\n", len);
					str[0] = '1';
					len++;
					
				}
				str[len-1] = '0';
				
			}
			else{
				len--;
			}
			cou++;
			
//			for(int i = 0; i < len; i++){
//				printf("%c", str[i]);
//			}
//			printf("\n");
		}
		
		printf("%d\n", cou);
//	}
	
	return 0;
}


/*
1	0
2	1
3	3

4	2
5	6
6	4
7	4

8	3
9	7
10	6
11	6
12	5
13 
14
15  5
16	4
*/