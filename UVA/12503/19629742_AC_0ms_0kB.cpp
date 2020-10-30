#include<stdio.h>
int main(){
	int T = 0;
	int N = 0;
	char instruction[10];
	int doo[102];
	scanf("%d", &T);
	for(int a=0; a<T; a++){
		scanf("%d", &N);
		int position = 0;
		for(int b=1; b<=N; b++){
			scanf("%s", instruction);
			if(instruction[0] == 'L'){
				position -= 1;
				doo[b] = -1;
//				printf("after left %d\n", position);
			} else if (instruction[0] == 'R'){
				position += 1;
				doo[b] = +1;
//				printf("after right %d\n", position);
			} else {
				int before = 0;
				char as[6];
				scanf("%s %d", as, &before);
				position += doo[before];
				doo[b] = doo[before];
//				printf("after as %d\n", position);
			}
		}
		printf("%d\n", position);
	}
	return 0;
}