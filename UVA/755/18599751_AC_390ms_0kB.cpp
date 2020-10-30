#include<stdio.h>
#include<string.h>

char num[100006][106];
char tukar[100006][106];

void merge(long long int L, long long int mid, long long int R){
	long long int left = L, right = mid+1, idx = 0;
	
	while(left <= mid && right <= R){
		if(strcmp(num[left], num[right]) < 0) strcpy(tukar[idx++], num[left++]);
		else strcpy(tukar[idx++], num[right++]);
	}
	
	long long int start;
	if(left > mid) start = right;
	else start = left;
	
	long long int end;
	if(left > mid) end = R;
	else end = mid;
	
	while(start <= end) strcpy(tukar[idx++], num[start++]); 
	
	for(long long int i=0; i<idx; i++) strcpy(num[L++], tukar[i]);
}

void mergeSort(long long int L, long long int R){
	if(R <= L) return;
	
	long long int mid = (L + R) / 2;
	mergeSort(L, mid);
	mergeSort(mid+1, R);
	merge(L, mid, R);
}

//void bubbleSort(long long int N){
//	for(long long int i=0; i<N; i++){
//		for(long long int j=i+1; j<=N; j++){
//			if(strcmp(num[i], num[j]) > 0){
//				strcpy(tukar, num[i]);
//				strcpy(num[i], num[j]);
//				strcpy(num[j], tukar);
//			}
//		}
//	}
//}

int main(){
	long long int T, N, i;
	long long int enter = 0;
	char numbers[16] = "0123456789";
	char huruf[53] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
	scanf("%lld", &T);
	for(long long int a=0; a<T; a++){
		if(enter == 1) printf("\n");
		
		scanf("%lld", &N);
		for(long long int b=0; b<N; b++){
			scanf("%s", num[b]);
			long long int strln = strlen(num[b]);
//			printf("%lld\n", strln);
			int i = 0;
			do{
				if(strchr(numbers, num[b][i]) == 0 && strchr(huruf, num[b][i]) == 0){
//					printf("index ke %lld bukan angka dan bukan huruf\n", i);
					long long int temp = i;
					while(temp < strln){
						num[b][temp] = num[b][temp+1];
						temp++;
					}
				}
				else if(strchr(numbers, num[b][i]) == 0){
//					printf("test1\n");
					if(num[b][i] == 'A' || num[b][i] == 'B' || num[b][i] == 'C') num[b][i] = '2';
					else if(num[b][i] == 'D' || num[b][i] == 'E' || num[b][i] == 'F') num[b][i] = '3';
					else if(num[b][i] == 'G' || num[b][i] == 'H' || num[b][i] == 'I') num[b][i] = '4';
					else if(num[b][i] == 'J' || num[b][i] == 'K' || num[b][i] == 'L') num[b][i] = '5';
					else if(num[b][i] == 'M' || num[b][i] == 'N' || num[b][i] == 'O') num[b][i] = '6';
					else if(num[b][i] == 'P' || num[b][i] == 'R' || num[b][i] == 'S') num[b][i] = '7';
					else if(num[b][i] == 'T' || num[b][i] == 'U' || num[b][i] == 'V') num[b][i] = '8';
					else if(num[b][i] == 'W' || num[b][i] == 'X' || num[b][i] == 'Y') num[b][i] = '9';
//					printf("index ke %lld diubah menjadi %c\n", i, num[b][i]);
					i++;
				}	
				else{
//					printf("index ke %lld angka\n", i);
					i++;
				}
				
			}while(num[b][i] != '\0');
//			printf("i = %lld\n", i);
//			printf("hasilnya = %s\n", num[b]);
		}
		
//		bubbleSort(N);
		mergeSort(0, N-1);
		
		long long int count = 0;
		long long int flag = 0;
//		printf("Order of sorted strings:");
		for(long long int c=1; c<=N; c++){
//			printf("%s\n", num[c]);
			if(strcmp(num[c], num[c-1]) == 0){
				count++;
			}
			else if(strcmp(num[c], num[c-1]) != 0 && count != 0){
				long long int put = 7;
				while(put > 3){
					num[c-1][put] = num[c-1][put-1];
					put--;
				}
				num[c-1][3] = '-';
				printf("%s %lld\n", num[c-1], count+1);
				flag = 1;
				count = 0;
			}
		}
		if(count == 0 && flag == 0) printf("No duplicates.\n");
		
		
		enter = 1;
	}
	
	return 0;
}