#include<bits/stdc++.h>

int main(){
	
	int n, s;
	scanf("%d %d", &n, &s);
	
	int max = 0;
	int num;
	for(int i = 0; i < n; i++){
		scanf("%d", &num);
		if(num > max) max = num;
	}
	float temp = (float)((float)max * (float)s) / 1000.0;  
	printf("%.0lf\n", ceil(temp));
	return 0;
}

/*
2 5
200 250

3 4
47 1032 1107


*/