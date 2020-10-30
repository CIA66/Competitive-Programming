#include<bits/stdc++.h>

int main(){
	
	FILE *fp = fopen("input.txt", "r");
	
	
	int n;
	fscanf(fp, "%d", &n);
	
	char arr[106];
	int inter = 0, count = 0, prev = -1, valid = 1;
	
	for(int i = 0; i < n; i++){
		fscanf(fp, "%c", &arr[i]);
		if(arr[i] == '1'){
			inter++;
			if(inter == 2){
				if(prev == -1){
					prev = count;
				}
				else if(count != prev){
					valid = 0;
					break;
				}
				count = 0;
				inter--;
			}
		}
		else if(arr[i] == '0'){
			if(inter == 1){
				count++;
			}
		}
	}
	FILE *fop = fopen("output.txt", "w");
	
	if(valid) fprintf(fop, "YES\n");
	else fprintf(fop, "NO\n");
	return 0;
}