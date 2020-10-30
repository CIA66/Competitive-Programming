#include <bits/stdc++.h>

using namespace std;

struct st{
	int x;
	int y;
	vector<int> path;
};

int m, n, grid[255][255], enx, eny, stx, sty, dist[255][255], ex[4] = {1, -1, 0 ,0}, ye[4] = {0, 0, 1, -1}, exex[4] = {2, -2, 0, 0}, yeye[4] = {0, 0, 2, -2};
st temp;
vector<int> tempp;
queue<st> qq;
bool flag = 0;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dist, -1, sizeof(dist));
	cin >> m >> n;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> grid[i][j];
			if(grid[i][j] == -1) {
				stx = i;
				sty = j;
			}
		}
	}
	cin >> enx >> eny;
	dist[stx][sty] = 0;
	temp.x = stx;
	temp.y = sty;
	temp.path = tempp;
	qq.push(temp);
	while(!qq.empty()) {
		st now = qq.front();
		if(now.x == enx && now.y == eny) {
			for(int i = 0; i < now.path.size(); i++) {
				if(i == now.path.size() - 1) {
					cout << now.path[i] << endl;
				}
				else {
					cout << now.path[i] << " ";
				}
			}
			flag = 1;
			break;
		}
		qq.pop();
		for(int i = 0; i < 4; i++) {
			if(dist[now.x+exex[i]][now.y+yeye[i]] != -1 || now.x+exex[i] < 1 || now.x+exex[i] > m || now.y+yeye[i] < 1 || now.y+yeye[i] > n || (grid[now.x+ex[i]][now.y+ye[i]] != grid[now.x+exex[i]][now.y+yeye[i]])) {
				continue;
			}
			else {
				st nex;
				nex.x = now.x+exex[i];
				nex.y = now.y+yeye[i];
				vector<int> temppath = now.path;
				temppath.push_back(grid[nex.x][nex.y]);
				nex.path = temppath;
				dist[nex.x][nex.y] = dist[now.x][now.y] + 1;
				qq.push(nex);
			}
		}
	}
	if(!flag) {
		cout << "impossible" << endl;
	}
}