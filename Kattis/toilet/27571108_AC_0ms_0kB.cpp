#include<bits/stdc++.h>

using namespace std;


int main(){

	char str[1006];
	scanf("%s", str);
	int len = strlen(str);
	
	int a = 0, b = 0, c = 0;
	for(int i = 1; i < len; i++){
		if(str[i] != str[i-1]){
			c++;
		}
		if(str[i] != 'U'){
			a+=2;
		} 
		if(str[i] != 'D'){
			b+=2;
		} 
	}
	if(str[1] == 'U' && str[0] == 'U'){
		b--;
	} 
	if(str[1] == 'D' && str[0] == 'D'){
		a--;
	}
	if(str[1] == 'D' && str[0] == 'U'){
		b++;
	} 
	if(str[1] == 'U' && str[0] == 'D'){
		a++;
	}
	printf("%d\n%d\n%d\n", a, b, c);
	
	return 0;
}