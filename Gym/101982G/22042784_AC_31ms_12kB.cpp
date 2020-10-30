#include<bits/stdc++.h>

int main(){
	
	double x, y, x1, y1, x2, y2;
	
	scanf("%lf %lf %lf %lf %lf %lf", &x, &y, &x1, &y1, &x2, &y2);
	
	double hasil;
	double a, b;
	if(x < x1){
		
		if(y < y1){
			a = x1-x; b = y1-y;
			if(a < 0) a *= -1;
			if(b < 0) b *= -1;
			hasil = sqrt((a)*(a) + (b)*(b));
		}
		else if(y > y2){
			a = x1-x; b = y-y2;
			if(a < 0) a *= -1;
			if(b < 0) b *= -1;
			hasil = sqrt((a)*(a) + (b)*(b));
		}
		else{
			hasil = x1 - x;
			if(hasil < 0) hasil *= -1;
		}
		
	}
	else if(x > x2){
		if(y < y1){
			a = y1 - y; b = x - x2;
			if(a < 0) a *= -1;
			if(b < 0) b *= -1;
			hasil = sqrt((a)*(a) + (b)*(b));
		}
		else if(y > y2){
			a = y - y2; b = x - x2;
			if(a < 0) a *= -1;
			if(b < 0) b *= -1;
			hasil = sqrt((a)*(a) + (b)*(b));
		}
		else{
			hasil = x - x2;
			if(hasil < 0) hasil *= -1;
		}
	}
	else{
		if(y < y1){
			hasil = y1 - y;
		}
		else if(y > y2){
			hasil = y - y2;
		}
	}
	
	printf("%.3lf\n", hasil);
	
	return 0;
}