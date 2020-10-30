#include<bits/stdc++.h>

using namespace std;

#define ll long long 



int main(){

	int t;
	scanf("%d", &t); getchar();
	char str[1006];
	for(int i = 0; i < t; i++){
		scanf("%[^\n]", str);
		int len = strlen(str);
		if(str[len-1] == 'o'){
			printf("FILIPINO\n");
		}
		else if(str[len-1] == 'u'){
			printf("JAPANESE\n");
		}
		else if(str[len-1] == 'a'){
			printf("KOREAN\n");
		}
		getchar();
	}
	return 0;
}

/*

8
kamusta_po
genki_desu
ohayou_gozaimasu
annyeong_hashimnida
hajime_no_ippo
bensamu_no_sentou_houhou_ga_okama_kenpo
ang_halaman_doon_ay_sarisari_singkamasu
si_roy_mustang_ay_namamasu

*/