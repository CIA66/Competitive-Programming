#include<stdio.h>
#include<string.h>

struct Data{
	char url[101];
	int relevance;
}data[101];

int main(){
	int T = 0;
	scanf("%d", &T);
	for(int a=0; a<T; a++){
		char url[101];
		int relevance = 0, max = 0;
		for(int b=0; b<10; b++){
			scanf("%s %d", url, &relevance);
			data[b].relevance = relevance;
			strcpy(data[b].url, url);
			if(relevance > max) max = relevance;
		}
		printf("Case #%d:\n", a+1);
		for(int c=0; c<10; c++){
			if(data[c].relevance == max){
				printf("%s\n", data[c].url);
			}
		}
	}
	return 0;
}