#include<bits/stdc++.h>

char vo[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};
void hanoi_tower(int N, char start[], char temp[], char end[]){
	if(N == 0) return;
	hanoi_tower(N-1, start, end, temp);
//	printf("Move disc %d, dari %s ke %s\n", N, start, end);
	printf("%c", vo[N-1]);
	hanoi_tower(N-1, temp, start, end);
}

int main(){
	
	int N;
	scanf("%d", &N);
	hanoi_tower(N, "Start", "Temp", "End");
	//printf("\n");
	
	return 0;
}