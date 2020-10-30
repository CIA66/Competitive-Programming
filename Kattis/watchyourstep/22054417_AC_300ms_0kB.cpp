#include <bits/stdc++.h>

using namespace std;

int edge[2505][2505],n,m,w,disc[2505],idx,low[2505],cnt,ej=0,ii=0,ans=0;
int ret[2505];
map<string,int> trn;
vector<int> adjlist[2505];
bool vis[2505];
stack<int> st;

void dfs(int now)
{
	disc[now]=idx;
	low[now]=idx;
	idx++;
	st.push(now);
	vis[now]=1;
	for(int i=0;i<adjlist[now].size();i++)
	{
		int next=adjlist[now][i];
		if(disc[next]==-1)
		{
			dfs(next);
			low[now]=min(low[now],low[next]);
		}
		else if(vis[next])
		{
			low[now]=min(low[now],low[next]);
		}
	}
	int w=0;
	if(low[now]==disc[now])
	{
		while(st.top()!=now)
		{
			w=st.top();
			//cout<<w<<", ";
			ret[ii]++;
			vis[w]=0;
			st.pop();
		}
		w=st.top();
		//cout<<w<<endl;
		vis[w]=0;
		st.pop();
		ret[ii]++;
		ii++;
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	memset(disc,-1,sizeof(disc));
	memset(vis,0,sizeof(vis));
	memset(low,-1,sizeof(low));
	
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> edge[i][j];
			if(edge[i][j] == 1) {
				ej++;
				adjlist[i].push_back(j);
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		if(disc[i]==-1)
		{
			dfs(i);
		}
	}
	
	for(int i = 0; i < ii; i++) {
		//cout<<ret[i]<<endl;
		ans = ans + ret[i]*(ret[i]-1);
		for(int j = i+1; j < ii; j++){
			ans = ans + ret[i]*ret[j];
		}
	}
	
	cout<<ans - ej << endl;
}