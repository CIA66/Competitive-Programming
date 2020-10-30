#include<bits/stdc++.h>

int main(){
	
	int k;
	scanf("%d", &k);
	
	getchar();
	char ans1[1006], ans2[1006];
	gets(ans1); gets(ans2);
	
	int len = strlen(ans1);
	int sama = 0, beda = 0;
	for(int i = 0; i < len; i++){
		if(ans1[i] == ans2[i]) sama++;
		else if(ans1[i] != ans2[i]) beda++;
	}
	int hasil = 0;
	if(sama == 0){
		hasil = beda - k;
	}
	else {
		int temp = sama - k;
		if(temp < 0) temp *= -1;
		hasil = len - temp;
	}
	
	printf("%d\n", hasil);
	return 0;
}