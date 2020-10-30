#include<stdio.h>

int count;

void hanoi(int N, char source, char spare, char target, int a){
	
	if(N == 1){
		count++;
		if(count == a) printf("%d : %c => %c\n", N, source, target);
		return;
	}
	
	hanoi(N-1, source, target, spare, a);
	
	count++;
	if(count == a) printf("%d : %c => %c\n", N, source, target);
	
	hanoi(N-1, spare, source, target, a);
}

int main(){
	
	int T, N, a;
	
	scanf("%d", &T);
	
	for(int i=0; i<T; i++){
		
		scanf("%d %d", &N, &a);
		
		count = 0;
		hanoi(N, 'A', 'B', 'C', a);
		
	}
	return 0;
}