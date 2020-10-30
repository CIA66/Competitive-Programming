#include<stdio.h>

int main(){
	
	int T = 0;
	while(scanf("%d", &T) != EOF){
		int t1 = 0, t2 = 0, f = 0, at = 0, ct1 = 0, ct2 = 0, ct3 =  0, c = 0;
		for(int a=1; a<=T; a++){
			scanf("%d %d %d %d %d %d %d", &t1, &t2, &f, &at, &ct1, &ct2, &ct3);
			
			if(ct1 <= ct2 && ct1 <= ct3){
				c = (ct2 + ct3) / 2;
			} else if(ct2 <= ct1 && ct2 <= ct3){
				c = (ct1 + ct3) / 2;
			} else if(ct3 <= ct1 && ct3 <= ct2){
				c = (ct1 + ct2) / 2;
			}
			
			int sum = 0;
			sum = t1 + t2 + f + at + c;
			if(sum >= 90){
				printf("Case %d: A\n", a);
			} 
			 else if(sum >= 80){
				printf("Case %d: B\n", a);
			} 
			 else if(sum >= 70){
				printf("Case %d: C\n", a);
			}
			 else if(sum >= 60){
				printf("Case %d: D\n", a);
			}
			 else if(sum < 60){
				printf("Case %d: F\n", a);
			}
		}
	}
	
	return 0;
}