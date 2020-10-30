#include<bits/stdc++.h>
 
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;
typedef map <str,int> mapsi;
typedef map <str,int> :: iterator mapsitr;
typedef map <int , int> mint;
typedef map <ll , ll> mll;
typedef set <int> si;
typedef set <ll> sll;
typedef si :: iterator sitr;
typedef si :: reverse_iterator rsitr;
typedef sll :: iterator sltr;
typedef sll :: reverse_iterator rsltr;
#define mset multiset
 
typedef mset <int> msi;
typedef mset <ll> msll;
typedef msi :: iterator msitr;
typedef msi :: reverse_iterator msritr;
typedef msll :: iterator msltr;
typedef msll :: reverse_iterator mslritr;
 
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define fs first.second
#define ss second.second
#define ff first.first
#define sf second.first
#define newl '\n'
 
char to_upper (char x){
    if( 97 <= int(x) && int(x) <= 122)return char(x-32);
    else if( 65 <= int(x) && int(x) <= 90)return x;
}
char to_lower (char x){
    if( 97 <= int(x) && int(x) <= 122)return x;
    else if( 65 <= int(x) && int(x) <= 90)return char(x+32);
}
int numerize (char x){
    if(48 <= int(x) && int(x) <= 57)return int(x-'0');
    else if( 97 <= int(x) && int(x) <= 122)return int(x-96);
    else if( 65 <= int(x) && int(x) <= 90)return int(x-64);
}
bool isect (int l1, int r1, int l2, int r2){
    pii p1,p2;
    p1 = mp(l1,r1); p2 = mp(l2,r2);
    if(p1>p2)swap(p1,p2);
    if(p2.fi <= p1.se)return true;
    else return false;
}
ll quickpow (ll num1, ll num2, ll MOD){
    if(num2==0)return 1;
    else if(num2==1)return num1;
    else{
        ll temp = quickpow (num1,num2/2,MOD); ll res = ((temp%MOD) * (temp%MOD))%MOD;
        if(num2%2==1) res = ((res%MOD)*(num1%MOD))%MOD; return res;
    }
}
ll invmod (ll num, ll MOD){return quickpow (num,MOD-2,MOD);}
ll gcd (ll num1, ll num2){
    if(num1 < num2) swap(num1,num2); ll num3 = num1 % num2 ;
    while(num3 > 0){ num1 = num2; num2 = num3; num3 = num1 % num2;}
    return num2;
}
ll lcm (ll num1 , ll num2){return (ll) (num1/__gcd(num1,num2))*num2;}
// end of Template

int n,m,vote[3000];
vi adj[30];
str ballot[3000];
int versus[30][30];
void resolve(int idx){
	for(int i=0;i<ballot[idx].size();i++){
		for(int j=i+1;j<ballot[idx].size();j++){
			int d1,d2;
			d1 = numerize(ballot[idx][i]);
			d2 = numerize(ballot[idx][j]);
			if(d1<d2){
				versus[min(d1,d2)][max(d1,d2)] += vote[idx];
			}
			else{
				versus[min(d1,d2)][max(d1,d2)] -= vote[idx];
			}
		}
	}
	
}
bool vis[30];
bool bfs(int start){
	queue <int> q;
	for(int i=0;i<=26;i++) vis[i] = false;
	q.push(start);
	int res = 0;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		if(!vis[node]){
			res++;
			vis[node] = true;
			for(int i=0;i<adj[node].size();i++) q.push(adj[node][i]);
		}
	}
	if(res==n) return true;
	else return false;
}
int main(){
 
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
 	cin>>n>>m;
 	for(int i=1;i<=m;i++){
 		cin>>vote[i]>>ballot[i];	
	}
	
	for(int i=1;i<=m;i++){
		resolve(i);
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(versus[i][j] > 0){
				adj[i].pb(j);
			}
			else if(versus[i][j]<0){
				adj[j].pb(i);
			}
		}
	}

	for(int i=1;i<=n;i++){
		cout<<char(i+64)<<": ";
		if(bfs(i)) cout<<"can win\n";
		else cout<<"can\'t win\n";
	}
}