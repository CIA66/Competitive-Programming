#include<bits/stdc++.h>
 
using namespace std;

#define MAXN 100000
#define ll long long

int Parent[MAXN + 10];
int Jumlah[MAXN + 10];

void makeSet(int n){
	for(int i=1; i<=n; i++){
		Parent[i] = i;
		Jumlah[i] = 1;
	}
}

int findParent(int x){
	if(Parent[x] == x) return x;
	return Parent[x] = findParent(Parent[x]);
}

void merge(int a, int b){
//	printf("%d : %d -- %d : %d\n", findParent(a), Jumlah[findParent(a)], findParent(b), Jumlah[findParent(b)]);
	Jumlah[findParent(b)] = Jumlah[findParent(b)] + Jumlah[findParent(a)];
	Parent[findParent(a)] = findParent(b);
}

int isSameSet(int a, int b){
	return findParent(a) == findParent(b);
}



int main(){
	
	int T, F;
	cin >> T; 
	
	map<string, int> mymap;
	
	
	string A, B;
	while(T--){
		cin >> F; 
		
		if(F*2 < 100000){
			makeSet(F*2);
		} else {
			makeSet(100000);
		}
		
		mymap.clear();
		int num = 1;
		
		while(F--){
			cin >> A >> B; 
			
			if(mymap.find(A) == mymap.end()){
				mymap[A] = num;
				num++;
			}
			if(mymap.find(B) == mymap.end()){
				mymap[B] = num;
				num++;
			}
			int numA, numB;
			numA = mymap[A];
			numB = mymap[B];
//			printf("num a:%d  b:%d\n", numA, numB);
			if(!isSameSet(numA, numB)){
				merge(numA, numB);
			}
			printf("%d\n", Jumlah[findParent(numA)]);
		}
		
	}
	return 0;
}

