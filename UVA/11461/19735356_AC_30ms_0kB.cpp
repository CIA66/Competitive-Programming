#include<stdio.h>
#include<math.h>

int main(){
	int a = 0, b = 0;
	while(1){
		int count = 0;
		scanf("%d %d", &a, &b);
		if(a == 0 && b == 0){
			break;
		}
		int temp = 0;
		for(int q=a; q<=b; q++){
			temp = sqrt(q);
			if(temp * temp == q){
				count++;
			}
		}
		printf("%d\n", count);
		
	}
	return 0;
}