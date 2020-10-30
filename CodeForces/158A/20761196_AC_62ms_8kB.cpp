#include<stdio.h>

int main(){
	
	int n, k;
	
	scanf("%d %d", &n, &k);
	
	int a = 0;
	int count = 0, go = 0, run = 0;
	for(int i=0; i<n; i++){
		scanf("%d", &a);
		
		if(run && a != go) break;
		if(run && a == go){
			count++;
		}
		if(!run && a > 0){
			count++;
		}
		if(count == k){
			go = a;
			run = 1;
		}
		
	}
	
	printf("%d\n", count);
	
	return 0;
}