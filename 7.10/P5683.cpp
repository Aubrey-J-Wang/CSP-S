#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

vector<int> gv[3005];
int dis[3][3005];

/*
dis[0]: Shortest path starting from 1.
dis[1]: Shortest path starting from s1.
dis[2]: SP starting from s2.
*/

void bfs(int root, int d[]) {
	d[root] = 0;
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i : gv[u]) {
			if(d[i] > d[u] + 1) d[i] = d[u] + 1, q.push(i);
		}
	}
	return;
}

int main() {
	int n, m, s1, t1, s2, t2;
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		gv[u].push_back(v);
		gv[v].push_back(u);
	}
	cin >> s1 >> t1 >> s2 >> t2;

	memset(dis, 0x3f, sizeof dis);

	bfs(1, dis[0]), bfs(s1, dis[1]), bfs(s2, dis[2]);

	int ans = 2e9;
	for(int i = 1; i <= n; i++)
		if(dis[0][i] + dis[1][i] <= t1 && dis[0][i] + dis[2][i] <= t2)
			ans = min(ans, dis[0][i] + dis[1][i] + dis[2][i]);

	if(ans == 2e9) ans = -1;
	else ans = m - ans; // m is the total number of paths.

	cout << ans;
	return 0;
}

