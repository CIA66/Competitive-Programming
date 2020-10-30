#include<bits/stdc++.h>

using namespace std;

int lala[300];

int main(){
//	printf("%d\n", lala['a']);
//	lala['a']++;
//	printf("%d\n", lala['a']);
	
//	printf("%d %d", 'A', 'z');

	char heading[206], text[206];
	scanf("%[^\n]", heading); getchar();
	int lenH = strlen(heading);
	for(int i = 0; i < lenH; i++){
		lala[heading[i]]++;
	}
	scanf("%[^\n]", text); getchar();
	int lenT = strlen(text);
	int found = 0;
	for(int i = 0; i < lenT; i++){
		if(('A' <= text[i] && text[i] <= 'Z') || ('a' <= text[i] && text[i] <= 'z')){
//			printf("%c\n", text[i]);
			if(lala[text[i]] == 0){
//				printf("---\n");
				found = 1;
				break;
			}
			lala[text[i]]--;
		}
	}
	
	if(found) printf("NO\n");
	else printf("YES\n");
	
	return 0;
}