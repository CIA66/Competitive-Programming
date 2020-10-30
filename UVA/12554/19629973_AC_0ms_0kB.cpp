#include<stdio.h>
#include<string.h>

int main(){
	int N = 0;
	char name[106][106];
	scanf("%d", &N);
	for(int a=0; a<N; a++){
		scanf("%s", name[a]);
	}
	int count = 16;
	int now = 0;
	int Rujia = 1;
	int circle = N;

	while(circle > 0){
		while(count > 0){
			for(int i=0; i<4; i++){
				printf("%s: ", name[now++]);
				if(now == N) now = 0;
				if(i == 0) printf("Happy\n");
				else if(i == 1) printf("birthday\n");
				else if(i == 2) printf("to\n");
				else {
					if(Rujia == 3) printf("Rujia\n");
					else printf("you\n");
					Rujia++;
					if(Rujia == 4) Rujia = 0;
				}
				count--;
			}
		}
		count = 16;
		circle -= 16;
	}
	
	
	return 0;
}