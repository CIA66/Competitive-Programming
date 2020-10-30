#include<stdio.h>

int big, small;
char B[1006][1006], S[1006][1006];

void printS(){
	for(int i=0; i<small; i++){
		printf("%s\n", S[i]);
	}
}

void reverseRows(){
	for(int i=0; i<small; i++){
		for(int j=0, k=small-1; j<k ; j++, k--){
			char temp = S[i][j];
			S[i][j] = S[i][k];
			S[i][k] = temp;
		}
	}
}

void transpose(){
	for(int i=0; i<small; i++){
		for(int j=i; j<small; j++){
			char temp = S[i][j];
			S[i][j] = S[j][i];
			S[j][i] = temp;
		}
	}
}


void rotate90(){
	transpose();
	reverseRows();
}

int cek(){
	int count = 0;
	int hasil = 0;
	for(int i=0; i<big; i++){
		for(int j=0; j<big; j++){
			count = 0;
			for(int k=0; k<small; k++){
				for(int l=0; l<small; l++){
					if(B[i+k][j+l] == S[k][l]){
						count++;
					} 
				}
			}
			if(count == small*small){
				hasil++;
			} 
		}
	}
	return hasil;
}



int main(){
	int count = 0;
	int hasil = 0;
	int print = 0;
	while(true){
		scanf("%d %d", &big, &small);
		if(big == 0 && small == 0) break;
		for(int a=0; a<big; a++){
			scanf("%s", B[a]);
		}
		for(int b=0; b<small; b++){
			scanf("%s", S[b]);
		}
		
		print = cek();
		printf("%d", print);
		for(int c=0; c<3; c++){
			rotate90();
//			printS();
			print = cek();
			printf(" %d", print);	
		}
		printf("\n");
	}
	
	
	return 0;
}