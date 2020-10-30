#include<stdio.h>
#include<string.h>

struct Data{
	char character;
	long long int sum;
	int urutan;
}data[30];


void merge(struct Data data[], int L, int mid, int R){
	struct Data temp[30];
	int left = L, right = mid+1, idx = 0;
	
	while(left <= mid && right <= R){
		if(data[left].sum < data[right].sum) temp[idx++] = data[left++];
		else temp[idx++] = data[right++];
	}
	
	int start;
	if(left > mid) start = right;
	else start = left;
	
	int end;
	if(left > mid) end = R;
	else end = mid;
	
	while(start <= end) temp[idx++] = data[start++];
	
	for(int i=0; i<idx; i++){
		data[L++] = temp[i];	
	}
	
}

void mergeSort(struct Data data[], int L, int R){
	if(R <= L) return;
	
	int mid = (L+R) / 2;
	mergeSort(data, L, mid);
	mergeSort(data, mid+1, R);
	
	merge(data, L, mid, R);
}




int main(){
	long long int N;
	while(scanf("%lld", &N) != EOF){
		char str[3000][300];
//		int alpha[30];
		int count = 0;
		for(int w=0; w<26; w++){
			data[w].sum = 0;
		}
		getchar();
		for(int a=0; a<N; a++){
			
			scanf("%[^\n]", str[a]);
			int len = strlen(str[a]);
			for(int b=0; b<len; b++){
				if('A' <= str[a][b] && str[a][b] <= 'Z'){
//					alpha[str[a][b] - 'A']++;
					data[str[a][b] - 'A'].character =  str[a][b];
					++data[str[a][b] - 'A'].sum;
					data[str[a][b] - 'A'].urutan =  count++;
				} else if('a' <= str[a][b] && str[a][b] <= 'z'){
					str[a][b] -= 32;
//					alpha[str[a][b] - 'A']++;
					data[str[a][b] - 'A'].character =  str[a][b];
					++data[str[a][b] - 'A'].sum;
					data[str[a][b] - 'A'].urutan =  count++;
				}
			}
//			for(int i=25; i>=0; i--){
//				if(data[i].sum > 0){
//					printf("%c %d\n", data[i].character, data[i].sum);
//				}
//			}
			getchar();
		}
		mergeSort(data, 0, 25);
		for(int i=25; i>= 0; i--){
			if(data[i].sum > 0){
				printf("%c %lld\n", data[i].character, data[i].sum);
			}
		}
	}
	return 0;
}