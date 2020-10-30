#include<bits/stdc++.h>

using namespace std;

#define ll long long 



int main(){

	int n;
	scanf("%d", &n);
	int sumB = 0, sumC = 0, num;
	for(int i = 0 ; i < n; i++){
		scanf("%d", &num);
		if(num > 0){
			sumB += num;
		}
		else{
			sumC += num;
		}
	}
	printf("%d\n", sumB - sumC);
	
	return 0;
}

/*


*/