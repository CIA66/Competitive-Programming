#include<stdio.h>
#include<string.h>
#define ll long long


ll mergee(char arr[], char temp[], ll left, ll mid, ll right){
	
	ll countt = 0;
	
	ll i = left, j = mid, k = left;
	
	while((i <= mid-1) && (j <= right)){
		
		if(arr[i] <= arr[j]) temp[k++] = arr[i++];
		else {
			temp[k++] = arr[j++];
			countt += (mid - i);
		}
	}
	
	while(i <= mid-1) temp[k++] = arr[i++];
	
	while(j <= right) temp[k++] = arr[j++];
	
	for(i = left; i <= right; i++){
		arr[i] = temp[i];
	}
	
	return countt;
}

ll mergeeSort(char arr[], char temp[], ll left, ll right){
	
	ll countt = 0;
	if(right > left){
		
		ll mid = (left + right) / 2;
		
		countt = mergeeSort(arr, temp, left, mid);
		countt += mergeeSort(arr, temp, mid+1, right);
		
		countt += mergee(arr, temp, left, mid+1, right);
	}
	return countt;
}

struct data{
	char asli[56];
	int count;
}Data[106];

void sortt(struct data tempo[], int N){
	
	for(int i = 0; i < N; i++){
		for(int j = N-1; j>=0; j--){
			if(tempo[j].count < tempo[j-1].count){
				struct data temp = tempo[j];
				tempo[j] = tempo[j-1];
				tempo[j-1] = temp;
			}
		}
	}
}
int main(){
	
	int T;
	scanf("%d", &T);
	
	getchar();
	
	for(int i = 0; i < T; i++){
		
//		if(i != 0) getchar();
		int n, m;
		scanf("%d %d", &n, &m);
		
		char str[106][56];
		
		for(int j = 0; j < m; j++){
			scanf("%s", Data[j].asli);
			strcpy(str[j], Data[j].asli);
		}
		
		char temp[106];
		int count[106];
		for(int j = 0; j < m; j++){
			Data[j].count = mergeeSort(str[j], temp, 0, n-1);
		}
		
		sortt(Data, m);
		
		for(int k = 0; k < m; k++){
//			printf("%s %d\n", Data[k].asli, Data[k].count);
			printf("%s\n", Data[k].asli);
		}
		if(i != T-1) printf("\n");
		
	}
	
	
	return 0;
}

/*

1
10 6
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT
*/