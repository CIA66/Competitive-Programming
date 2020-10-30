#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	
	double n, m, a;
	scanf("%lf %lf %lf", &n, &m, &a);
	
	double count1 = 0, count2 = 0;
	
	count1 = ceil(n / a);
	count2 = ceil(m / a);
	
	
	double ans = count1 * count2;
	printf("%lld\n", (ll)ans);
	
	return 0;
}