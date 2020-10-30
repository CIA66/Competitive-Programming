#include<stdio.h>

int Min(int a, int b){
	if(a < b) return a;
	return b;
}

int Max(int a, int b){
	if(a < b) return b;
	return a;
}

int Pengurangan(int a, int b){
	
	int count = 0;
	
	int min = Min(a, b);
	int max = Max(a, b);
	
	
	while(min > 0 && max > 0){
		
		if(min == max){
			count++;
			max -= min;
		}
		else{
			count += (max / min);
			max = max % min;
			if(max < min){
				int temp = max;
				max = min;
				min = temp;
			}
		}
	}
	
	return count;
}

int main(){
	
	int n;
	int a, b;
	
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d %d", &a, &b);
		
		printf("%d\n", Pengurangan(a, b));
	}
	return 0;
}