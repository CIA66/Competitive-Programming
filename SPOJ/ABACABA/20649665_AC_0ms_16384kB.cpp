#include<stdio.h>

void cetak(int N){
	
	if(N == 1){
		printf("%c", N+'A'-1);
		return;	
	} 
	
	cetak(N-1);
	
	printf("%c", N+'A'-1);
	
	cetak(N-1);
	
}

int main(){
	
	int N;
	
	scanf("%d", &N);
	
	cetak(N);
	
	
	return 0;
}