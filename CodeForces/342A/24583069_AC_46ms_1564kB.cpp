#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define inf 100000000

int main(){
	
	int numbers[10] = {0};
	int n;
	scanf("%d", &n);
	int num;
	for(int i = 0; i < n; i++){
		scanf("%d", &num);
		numbers[num]++;
	}
	
	int packet[40000][10];
	int found = -1, idx = 1, now = 7;
	
	if(numbers[5] != 0 || numbers[7] != 0) found = 0;
	else if(numbers[4] == 0 && numbers[6] == 0) found = 0;
	else{
		int bukanTiga = 0;
		while(1){
			if(numbers[6] != 0){
				if(numbers[3] != 0 && bukanTiga == 0){
					if(numbers[1] != 0){
						while(numbers[1] != 0 && numbers[3] != 0 && numbers[6] != 0){
							int mini = min(numbers[1], numbers[3]);
							mini = min(mini, numbers[6]);
							numbers[1]-= mini; numbers[3]-= mini; numbers[6]-= mini;
							for(int k = 0; k < mini; k++){
								packet[idx][1] = 1;
								packet[idx][2] = 3;
								packet[idx][3] = 6;
								idx++;
							}
						}
					}
					else {
						bukanTiga = 1;
					}
				}
				else if(numbers[2] != 0){
					if(numbers[1] != 0){
						while(numbers[1] != 0 && numbers[2] != 0 && numbers[6] != 0){
							int mini = min(numbers[1], numbers[2]);
							mini = min(mini, numbers[6]);
							numbers[1]-= mini; numbers[2]-= mini; numbers[6]-= mini;
							for(int k = 0; k < mini; k++){
								packet[idx][1] = 1;
								packet[idx][2] = 2;
								packet[idx][3] = 6;
								idx++;
							}
						}
					}
					else{
						found = 0;
						break;
					}
				}
				else{
					found = 0;
					break;
				}
			}
			else if(numbers[4] != 0){
				if(numbers[2] != 0){
					if(numbers[1] != 0){
						while(numbers[1] != 0 && numbers[2] != 0 && numbers[4] != 0){
							int mini = min(numbers[1], numbers[2]);
							mini = min(mini, numbers[4]);
							numbers[1]-= mini; numbers[2]-= mini; numbers[4]-= mini;
							for(int k = 0; k < mini; k++){
								packet[idx][1] = 1;
								packet[idx][2] = 2;
								packet[idx][3] = 4;
								idx++;
							}
						}
					}
					else{
						found = 0;
						break;
					}
				}
				else{
					found = 0;
					break;
				}
			}
			else{
				break;
			}
		}
//		printf("  %d\n", idx);
		if((idx-1) * 3 != n) found = 0;
		else if(found == -1) found = 1;
	}
	
	if(!found) printf("-1\n");
	else{
		for(int i = idx-1; i >= 1; i--){
			for(int k = 1; k <= 3; k++){
				if(k == 1) printf("%d", packet[i][k]);
				else printf(" %d", packet[i][k]);
			}
			printf("\n");
		}
	}
	
	return 0;
}

/*
6
2 2 1 1 4 6
*/