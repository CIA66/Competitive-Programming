#include<stdio.h>
#include<string.h>

struct Data{
	char name[16];
	int money;
	int gift;
}data[11];

int main(){
	int N = 0; 
	int start = 0;
	while(scanf("%d", &N) != EOF){
		
		for(int a=0; a<11; a++){
			data[a].gift = data[a].money = 0;
			strcpy(data[a].name, "");
		}
		
		char name[16] = "";
		for(int b=0; b<N; b++){
			getchar();
			scanf("%s", name); 
			strcpy(data[b].name, name);
		}
		
		int money = 0, people = 0;
		char nameTo[16] = "";
		
//		printf("N : %d\n", N);
		for(int c=0; c<N; c++){
			getchar();
			scanf("%s %d %d", name, &money, &people); 
				
				if(people != 0){
					int toGift = money / people;
					for(int d=0; d<N; d++){
						if(strcmp(name, data[d].name) == 0){
							data[d].money += toGift * people;
							break;
						}
					}
					
					if(money != 0){
						for(int e=0; e<people; e++){
							getchar();
							scanf("%s", nameTo); 
							for(int f=0; f<N; f++){
								if(strcmp(nameTo, data[f].name) == 0){
									data[f].gift += toGift;
									break;
								}
							}
						}
					}
					else {
						for(int k=0; k<people; k++){
							getchar();
							scanf("%s", nameTo);
						}
						
					}
					
				}
				
//				for(int a=0; a<N; a++){
//					printf("%s money = %d gift = %d\n", data[a].name, data[a].money, data[a].gift);
//				}
//				printf("\n");
			
		}
		if(start == 0) {
			start = 1;
		} else {
			printf("\n");
		}
		for(int g=0; g<N; g++){
			printf("%s %d\n", data[g].name, (data[g].gift - data[g].money));
		}
		
//		getchar();
	}
	return 0;
}