#include<stdio.h>
#include<string.h>

struct Data{
	char asli[76];
	int countAsli;
}data[76];

int check(char keyword[][26], int K, char str[]){
	
	for(int i = 0; i < K; i++){
		if(strcmp(keyword[i], str) == 0) return 1;
	}
	return 0;
}

int sort(int E){
	
	for(int i = 0; i < E; i++){
		for(int k = E-1; k > i; k--){
			if(data[k].countAsli < data[i].countAsli){
				struct Data temp = data[i];
				data[i] = data[k];
				data[k] = temp;
			}
		}
	}
	return data[E-1].countAsli;
}
int main(){
	
//	printf("%c\n", 'A' + 32);
	int K , E, tc = 1;
	char keyword[26][26];
	char txt[76], str[76], spc;
	
	while(scanf("%d %d", &K, &E) != EOF){
		
		for(int i = 0; i < 71; i++){
			strcpy(data[i].asli, "");
			data[i].countAsli = 0;
		}
		
		
		getchar();
		for(int i = 0; i < K; i++){
			scanf("%s", keyword[i]);
		}
		
		int adaSama = 0;
		for(int i = 0; i < E; i++){
			int count = 0;
			getchar();
			scanf("%[^\n]", txt);
			strcpy(data[i].asli, txt);
//			printf("%s\n", data[i].asli);
			int lenTxt = strlen(txt);
	
//			printf("---\n");
			int idx = 0, sama = 0;
			for(int k = 0; k < lenTxt; k++){
				if('A' <= txt[k] && txt[k] <= 'Z'){
					str[idx] = txt[k] + 32;
					idx++;
				}
				else if('a' <= txt[k] && txt[k] <= 'z'){
					str[idx] = txt[k];
					idx++;
				}
				else{
					str[idx] = '\0';
//					printf("check  %s\n", str);
					sama = check(keyword, K, str);
					if(sama){
						adaSama = 1;
						count++;
					}
					strcpy(str, "");
					idx = 0;
					sama = 0;
				}
			}
			str[idx] = '\0';
//					printf("check  %s\n", str);
			sama = check(keyword, K, str);
			if(sama){
				adaSama = 1;
				count++;
			}
			strcpy(str, "");
			idx = 0;
			sama = 0;
				
			data[i].countAsli = count;
//			printf("%d\n", data[i].countAsli);
		}
		
		printf("Excuse Set #%d\n", tc);
		tc++;
		int max;
		if(adaSama){
			max = sort(E);
			for(int i = E-1; i >= 0; i--){
				if(data[i].countAsli != max) break;
	//			printf("%s -- %d\n", data[i].asli, data[i].countAsli);
				printf("%s\n", data[i].asli);
			}
		}
		else {
			for(int i = 0; i < E; i++){
				printf("%s\n", data[i].asli);
			}
		}
		
		
		
		printf("\n");
	}
	
	return 0;
}

/*

1 2
a
ab
a

1 2
as
asdf
adcxvcs


5 3
dog
ate
homework
canary
died
My dog ate my homework.
Can you believe my dog died after eating my canary... AND MY HOMEWORK?
This excuse is so good that it contain 0 keywords.
6 5
superhighway
crazy
thermonuclear
bedroom
war
building
I am having a superhighway built in my bedroom.
I am actually crazy.
1234567890.....,,,,,0987654321?????!!!!!!
There was a thermonuclear war!
I ate my dog, my canary, and my homework ... note outdated keywords?


*/