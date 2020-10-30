#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
//	printf("%lf\n", acos(-1));
	int T;
	scanf("%d", &T);
	double L, w, r, red, green;
	for(int i = 0; i < T; i++){
		scanf("%lf", &L);
		r = L / 5.0;
		red = acos(-1) * r * r;
		w = 6 * (L / 10);
		green = (L * w) - red;
		printf("%.2lf %.2lf\n", red, green);
	}
	return 0;
}