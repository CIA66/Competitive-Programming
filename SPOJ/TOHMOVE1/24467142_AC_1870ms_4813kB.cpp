#include<bits/stdc++.h>

int now;
void hanoi_tower(int N, char start[], char temp[], char end[], int target){
	if(N == 0) return;
	hanoi_tower(N-1, start, end, temp, target);
//	printf("Move disc %d, dari %s ke %s\n", N, start, end);
now++;
	if (now == target) printf("%d : %s => %s\n", N, start, end);
//	else printf("%d : %s => %s    %d\n", N, start, end, now);
//	printf("%c", vo[N-1]);
	hanoi_tower(N-1, temp, start, end, target);
}

int main(){
	
	int T, N, target;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &N, &target);
		now = 0;
		hanoi_tower(N, "A", "B", "C", target);
	}
	
	
	return 0;
}