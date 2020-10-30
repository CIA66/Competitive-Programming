#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define MAXN 1000000

unsigned long int fact(unsigned long int x){
	unsigned long int hasil = 1;
	while(x != 1){
		hasil *= x;
		x--;
	}
	return hasil;
}

int main(){

//	printf("%d %d\n", 'A', 'Z');
	int t;
	scanf("%d", &t); getchar();
	for(int tc = 1; tc <= t; tc++){
		
		int capital[100];
		for(int i = 'A'; i <= 'Z'; i++){
			capital[i] = 0;
		}
		char word[26];
		scanf("%s", word);
		int len = strlen(word);
		for(int i = 0; i < len; i++){
			capital[word[i]]++;
		}
		
		unsigned long int hasil;
		hasil = fact(len);
		for(int i = 'A'; i <= 'Z'; i++){
			if(capital[i] > 1){
				hasil /= fact(capital[i]);
			}
		}
		
		printf("Data set %d: %lu\n", tc, hasil);
	}
	return 0;
}