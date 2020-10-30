#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;

int Arr[1100006];

void Storage(){
	
	Arr[1] = 0;
	Arr[2] = 1;
	
	for(int n=3; n<1100001; n++){
		Arr[n] = (Arr[n-1] + Arr[n-2]) % 100000;
	}
}

int main(){
	
	Storage();
	
	int T;
	
	scanf("%d", &T);
	
	int A, B;
	for(int i=1; i<=T; i++){
		
		scanf("%d %d", &A, &B);
		
		priority_queue <int> myPQ;
		
		int idx = 1;
		for(int k = A; k <= (A+B); k++){
			
			myPQ.push(Arr[k] * (-1));
			idx++;
		}
		
		printf("Case %d: ", i);
		
		int x;
		for(x = 1; x < idx-1; x++){
			
			if(x == 100) {
				break;
			}
			else{
				printf("%d ", myPQ.top() * (-1));
				myPQ.pop();
			}
		}
		printf("%d\n", myPQ.top() * (-1));
	}
	return 0;
}