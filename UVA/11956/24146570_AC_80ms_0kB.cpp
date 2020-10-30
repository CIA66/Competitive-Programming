#include<stdio.h>
#include<string.h>

char str[100100];
		
int main(){
	
//	printf("%.02X", 100);

//	int x = 255;
//	printf("%.03X\n", x);

	int N;
	scanf("%d", &N); getchar();
	
	int tc = 1;
	while(N--){
		int ans[106];
		for(int i = 0; i < 101; i++){
			ans[i] = 0;
		}
		
//		gets(str);
		scanf("%s", str);
//		printf("%s\n", str);
		int len = strlen(str);
		
		int idx = 0;
		for(int i = 0; i < len; i++){
			char now = str[i];
			if(now == '>'){
				idx++;
				if(idx == 100){
					idx = 0;
				}
			}
			else if(now == '<'){
				idx--;
				if(idx < 0){
					idx = 99;
				}
			}
			else if(now == '+'){
				ans[idx]++;
				if(ans[idx] == 256){
					ans[idx] = 0;
				}
			}
			else if(now == '-'){
				ans[idx]--;
				if(ans[idx] < 0){
					ans[idx] = 255;
				}
			}
			else if(now == '.'){
				continue;
			}
			
		}
		
		printf("Case %d:", tc);
		tc++;
		for(int i = 0; i < 100; i++){
			printf(" %02X", ans[i]);
		}
		printf("\n");
	}
	
	return 0;
}

/*

1
..++<><<+++>>++++++++++++++++++++++++++>>>+++<+...++<><<+++>>++++++++++++++++++++++++++>>>+++<+...++<><<+++>>++++++++++++++++++++++++++>>>+++<+.

*/

