#include<stdio.h>
#include<math.h>



#define MAXN 10000

int Parent[MAXN + 10];

void makeSet(int n){
	for(int i=1; i<=n; i++){
		Parent[i] = i;
	}
}

int findParent(int x){
	if(Parent[x] == x) return x;
	return Parent[x] = findParent(Parent[x]);
}

void merge(int a, int b){
	Parent[findParent(a)] = findParent(b);
}

int isSameSet(int a, int b){
	return findParent(a) == findParent(b);
}

struct edge{
	int a, b;
	double cost;
};

struct edge arr[10000];

struct Titik{
	double x, y;
}titik[106];

int main(){
	int T = 0;
	scanf("%d", &T);
//	getchar();
//	puts("");
	for(int u=0; u<T; u++){
		int N = 0; // V
		scanf("%d", &N);
		
		for(int r=0; r<=N; r++){
			Parent[r] = 0;
		}
		
		makeSet(N);
//		for(int r=0; r<=N; r++){
//			printf("%d ", Parent[r]);
//		}
//		puts("");
		
		for(int j=0; j<N; j++){
			double x, y;
			scanf("%lf %lf", &x, &y);
			titik[j].x = x;
			titik[j].y = y;
		}
		
		int idx = 0;
//		printf("idx : %d\n", idx);
		for(int k=0; k<N; k++){
			for(int l=k+1; l<N; l++){
				arr[idx].a = k;
				arr[idx].b = l;
				double tempCost = sqrt(pow(titik[l].x - titik[k].x, 2) + pow(titik[l].y - titik[k].y, 2));
				arr[idx].cost = tempCost;
				idx++;
			}
		}
//		printf("idx after : %d\n", idx);
		for(int i=idx-1; i>0; i--){
			for(int k=0; k<i; k++){
				if(arr[k].cost > arr[k+1].cost){
					struct edge temp = arr[k];
					arr[k] = arr[k+1];
					arr[k+1] = temp;
				}
			}
		}
		
//		for(int i=0; i<idx; i++){
//			printf("%d - %d : %lf\n", arr[i].a, arr[i].b, arr[i].cost);
//		}

		double MSTcost = 0.0;
		
		for(int q=0; q<idx; q++){
			if(isSameSet(arr[q].a, arr[q].b)){
//				printf("%d - %d continue\n", arr[q].a, arr[q].b);
				continue;
			}
			MSTcost += arr[q].cost;
			merge(arr[q].a, arr[q].b);
//			printf(" Edge MST : %d %d --> %lf\n", arr[q].a, arr	[q].b, arr[q].cost);
		}
		
		printf("%.2lf\n", MSTcost);
		if(u != T-1) puts("");
	}
	return 0;
}