#include <iostream>
#include <vector>
const int MAXN = 500010;
using namespace std;

int n, m, num;
int father[MAXN];
int f[MAXN][50], dis[MAXN][50];
int depth[MAXN], log_2[MAXN], visited[MAXN];
vector<pair<int, int> > tree[MAXN];

struct edge_graph {
	int u, v, w;
} edge[MAXN];

int find(int x) {
	while(x != father[x]) x = father[x] = father[father[x]];
	return x;
}

bool cmp(edge_graph x, edge_graph y) {
	return x.w > y.w;
}

void dfs(int x, int fath, int we) {
	visited[x] = 1;
	depth[x] = depth[fath] + 1;
	f[x][0] = fath, dis[x][0] = we;
	
	for(int i = 1; (1 << i) <= depth[x]; i++) {
		f[x][i] = f[f[x][i - 1]][i - 1];
		dis[x][i] = min(dis[x][i - 1], dis[f[x][i - 1]][i - 1]);
	}
	
	for(auto [v, w] : tree[x]) {
		if(v != fath)
			dfs(v, x, w);
	}
	
	return;
}

int lca(int x, int y) {
	if(find(x) != find(y)) return -1;
	
	int ans = INT_MAX;
	
	if(depth[x] < depth[y]) swap(x, y);
	
	while(depth[x] > depth[y]) {
		ans = min(ans, dis[x][log_2[depth[x] - depth[y]] - 1]);
		x = f[x][log_2[depth[x] - depth[y]] - 1];
	}
	
	if(x == y) return ans;
	
	for(int i = log_2[depth[x]] - 1; i >= 0; i--) {
		if(f[x][i] != f[y][i]) {
			ans = min(ans, dis[x][i]);
			ans = min(ans, dis[y][i]);
			x = f[x][i];
			y = f[y][i];
		}
	}
	
	ans = min(ans, min(dis[x][0], dis[y][0]));
	return ans;
}

int main() {
	cin >> n >> m;
	
	for(int i = 1; i <= m; i++) cin >> edge[i].u >> edge[i].v >> edge[i].w;
		
	for(int i = 1; i <= n; i++) father[i] = i, log_2[i] = log_2[i - 1] + (1 << log_2[i - 1] == i);
	
	sort(edge + 1, edge + m + 1, cmp);
	
	for(int i = 1; i <= m; i++) {
		int eu, ev;
		eu = find(edge[i].u), ev = find(edge[i].v);
		
		if(eu == ev) continue;
		
		father[eu] = ev;
		tree[edge[i].u].push_back({edge[i].v, edge[i].w});
		tree[edge[i].v].push_back({edge[i].u, edge[i].w});
		
		if(++num == n) break;
	}
	
	for(int i = 1; i <= n; i++) {
		if(!visited[i]) dfs(i, 0, 0);
	}
	
	int q;
	cin >> q;
	
	while(q--) {
		int x, y;
		cin >> x >> y;
		cout << lca(x, y);
	}
	
	return 0;
}

