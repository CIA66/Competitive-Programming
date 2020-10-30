#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	
	int N;
	while(1){
		scanf("%d", &N);
		if(N == 0) break;
		int x = 1, y = 1;
		if(N == 1){
			printf("%d %d\n", x, y);
		}
		else{
			for(int i = 1; i <= N; i++){
				if(i*i < N && N <= (i+1)*(i+1)){
					int ada = 0, now;
					if((i+1) % 2 == 0){
						
						x = i+1;
						y = 1;
						now = (i+1)*(i+1);
						for(int k = 1; k < i+1; k++){
							if(now == N){
								ada = 1;
							}
							else{
								now--;
								y++;
							}
						}
						if(ada == 0){
							for(int k = 1; k < i+1; k++){
								if(now == N){
									ada = 1;
								}
								else{
									now--;
									x--;
								}
							}
						}
					}
					else if((i+1) % 2 == 1){
						y = i+1;
						x = 1;
						now = (i+1)*(i+1);
						for(int k = 1; k < i+1; k++){
							if(now == N){
								ada = 1;
								break;
							}
							else{
								now--;
								x++;
							}
						}
						if(ada == 0){
							for(int k = 1; k < i+1; k++){
								if(now == N){
									ada = 1;
									break;
								}
								else{
									now--;
									y--;
								}
							}
						}
					}
					printf("%d %d\n", x, y);
					break;
				}
			}
		}
		
	}
	
	return 0;
}