#include<stdio.h>

int main(){
	
	int a1, a2, k1, k2, n;
	scanf("%d", &a1); scanf("%d", &a2); scanf("%d", &k1); scanf("%d", &k2); scanf("%d", &n);
	
	int eachMin, eachMax, bykMin, bykMax;

	if(k1 < k2){
		eachMin = k1; eachMax = k2;
		bykMin = a1; bykMax = a2;
	}
	else{
		eachMin = k2; eachMax = k1;
		bykMin = a2; bykMax = a1;
	}
	
	int sumMin = 0, sumMax = 0;
	
	int n1 = n;
	if(n1 <= eachMin*bykMin){
		sumMax = n1 / eachMin;
	}
	else{
		sumMax += bykMin;
		n1 -= (eachMin*bykMin);
		sumMax += n1 / eachMax;
	}
	
	int n2 = n;
	n2 -= (bykMin*(eachMin-1) + bykMax*(eachMax-1));
	if(n2 <= 0) sumMin = 0;
	else sumMin = n2;
	
	printf("%d %d\n", sumMin, sumMax);
	
	return 0;
}