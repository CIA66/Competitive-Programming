#include<stdio.h>

int main(){
	char op1, op2;
	char jawab[6];
	int num1 = 0, num2 = 0;
	int correct = 0;
	while(scanf("%d%c%d%c%s", &num1, &op1, &num2, &op2, jawab) != EOF){
		int bener = 0, valid = 0, jawabannya = 0;
		if(jawab[0] == '?'){
			continue;
		}
		sscanf(jawab, "%d", &jawabannya);
		if(op1 == '+'){
			bener = num1 + num2;
			if(bener == jawabannya){
				correct++;
			}
		} else if(op1 == '-') {
			bener = num1 - num2;
			if(bener == jawabannya){
				correct++;
			}
		}
	}
	printf("%d\n", correct);
	return 0;
}