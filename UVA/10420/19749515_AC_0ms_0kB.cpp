#include<stdio.h>
#include<string.h>

struct Data{
	char list[100];
	int listSum;
}data[2006];

void sort(int count){
	for(int a=0; a<count-1; a++){
		for(int b=0; b<count-a-1; b++){
			if(strcmp(data[b].list, data[b+1].list) > 0){
				struct Data temp = data[b];
				data[b] = data[b+1];
				data[b+1] = temp;
			}
		}
	}
}

int main(){
	int N = 0;
	char str[100], country[50];
	strcpy(str, "");
	strcpy(country, "");
	int count = 0;
	
	while(scanf("%d", &N) != EOF){
		for(int a=0; a<N; a++){
			int baru = 1;
			scanf("%s %[^\n]", country, str);
			
			if(count == 0){
				strcpy(data[count].list, country);
				data[count].listSum = 1;
				count++;
				baru = 0;
			}
			else {
				for(int b=0; b<=count; b++){
					if(strcmp(data[b].list, country) == 0){
						data[b].listSum += 1;
						baru = 0;
					}
				}
			}
			if(baru){
				strcpy(data[count].list, country);
				data[count].listSum += 1;
				count++;
			}
			getchar();
		}
//		printf("Count : %d\n", count);
		sort(count);
		
		for(int i=0; i<count; i++){
			printf("%s %d\n", data[i].list, data[i].listSum);
		}
		
		strcpy(str, "");
	}
	return 0;
}