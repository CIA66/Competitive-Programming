#include<stdio.h>
#include<string.h>

#define NO_OF_CHARS 256

struct Data{
	char asli[86];
	char kecil[86];
	int teman;
}data[1006];

int isAnagram(char str1[], char str2[]){
	
	int len1 = strlen(str1), len2 = strlen(str2);
	if(len1 != len2) return 0;
	
	int count[NO_OF_CHARS] = {0};
	int i;
	for(i = 0; i < len1 ; i++){
		count[str1[i]]++;
		count[str2[i]]--;
	}
		
	for(i = 0; i < NO_OF_CHARS; i++){
		if(count[i])
			return 0;
	}
	return 1;
}

void sort(char arr[][86], int n){
	
	char temp[86];
	for(int i = 0; i < n; i++){
		for(int k = n-1; k > i; k--){
			if(strcmp(arr[i], arr[k]) > 0){
				strcpy(temp, arr[i]);
				strcpy(arr[i], arr[k]);
				strcpy(arr[k], temp);
			}
		}
	}
	
}


int main(){
	
	int count = 0;
//	printf("%d\n", isAnagram("ladder", "leader"));
	while(1){
		scanf("%s", data[count].asli);
		if(data[count].asli[0] == '#') break;
		int ii = strlen(data[count].asli), x = 0, kk = 0;
		for(x = 0; x < ii; x++){
			if('A' <= data[count].asli[x] && data[count].asli[x] <= 'Z'){
				data[count].kecil[kk] = data[count].asli[x] + 32;
			}
			else{
				data[count].kecil[kk] = data[count].asli[x];
			}
			kk++;
		}
		data[count].kecil[kk] = '\0';
		data[count].teman = 0;
		count++;
	}
	char ans[1006][86]; int idx = 0, ada = 0; 
	for(int i = 0; i < count; i++){

		if(data[i].teman == 1) continue;
		for(int j = i+1; j < count; j++){
			if(isAnagram(data[i].kecil, data[j].kecil)){
//				printf(" Anaa -- %s %s\n", data[i].kecil, data[j].kecil);
				data[j].teman = 1;
				data[i].teman = 1;
				ada = 1;
			}
		}
		if(!ada){
			strcpy(ans[idx], data[i].asli);
//			printf(" Gk Ada -- %s %s\n", ans[idx]);
			idx++;
		}
		ada = 0;
	}
//	printf("idx %d\n", idx);
	sort(ans, idx);
	for(int i = 0; i < idx; i++){
		printf("%s\n", ans[i]);
	}
	
	
	return 0;
}

/*

ladder came tape soon leader acme RIDE lone Dreis peat
ScAlE orb eye Rides dealer NotE derail LaCeS drIed
noel dire Disk mace Rob dries
#

*/