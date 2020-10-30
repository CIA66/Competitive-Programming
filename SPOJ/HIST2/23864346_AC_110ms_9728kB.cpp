#include<stdio.h>
#include<math.h>


int n;
int hist[26];

struct answer{
	int maxPerim;
	int count;
};

struct answer memo[20][(1 << 16)];

struct answer solve(int idx, int mask){
	
	if(memo[idx][mask].maxPerim != -1){
		return memo[idx][mask];
	}
				// 2^n
	if(mask == ((1 << n) - 1)){
		return {hist[idx], 1};
	}
	
	struct answer retans;
	retans.maxPerim = 0;
	retans.count = 1;
	
	for(int i = 1; i <= (n-1); i++){
		
		if((mask & (1 << i)) > 0){
			continue;
		}
		
		struct answer tempAnswer;
		tempAnswer = solve(i, mask | (1 << i));
		tempAnswer.maxPerim += abs(hist[idx] - hist[i]) + 2;  // ketika kita pergi ke dia 
		
		if(tempAnswer.maxPerim > retans.maxPerim){
			retans.maxPerim = tempAnswer.maxPerim;
			retans.count = tempAnswer.count;
		}
		else if(tempAnswer.maxPerim == retans.maxPerim){
			retans.count += tempAnswer.count;
		}
	}
	
	return memo[idx][mask] = retans;
}

int main(){
	
	while(scanf("%d", &n) != EOF){
		
		if(n == 0) break;
		hist[0] = 0;
		
		for(int i = 1; i <= n; i++){
			scanf("%d", &hist[i]);
		}
		
		hist[n+1] = 0;
		n += 1; //hanya yg depan saja
		
		struct answer ans;
		for(int i = 0; i < 16; i++){
			
			for(int k = 0; k < (1 << 16); k++){
				memo[i][k] = {-1, -1};
			}
		}
		ans = solve(0, (1 << 0));
		printf("%d %d\n", ans.maxPerim, ans.count);
	}
	
	return 0;
}

/*

4
1 2 3 4
3
2 6 5
0

*/
