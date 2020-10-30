#include<stdio.h>

int main(){
	
	int x , y , min ; 
 
 	scanf("%d %d",&x,&y );
 	
	if( x < y )
	min = x;
	else 
	min = y;
	
	printf("%d\n",min+1);
	
	for( int i = 0 , j = min ; i <= min ; i++ , j--){
		printf("%d %d\n",i,j);
	}
	
	return 0 ; 
}