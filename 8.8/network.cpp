#include<iostream>
#include<queue>
#define int long long
using namespace std;

const int maxv = 1e5+5;

int head[maxv], vis[maxv], d[maxv];
int fa[maxv][20], val[maxv], ff[maxv];
int n, m, edgenum, ans;

struct node {
	int to, next;
} edge[maxv << 1];

void init() {
	fill(d, d + maxv, 0);
	fill(head, head + maxv, -1);
	fill(ff, ff + maxv, 0);
	fill(val, val + maxv, 0);
	edgenum = 0;
}

void addedge(int u, int v) {
	edge[edgenum].to = v;
	edge[edgenum].next = head[u];
	head[u] = edgenum++;
}

void bfs() {
	queue<int> q;
	q.push(1);
	d[1] = 1;
	
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		
		for(int i = head[now]; i != -1; i = edge[i].next) {
			int y = edge[i].to;
			
			if(d[y]) continue;
			
			d[y] = d[now] + 1;
			fa[y][0] = now;
			
			for(int j = 1; j < 20; j++)
				fa[y][j] = fa[fa[y][j - 1]][j - 1];
				
			q.push(y);
		}
	}
}

int lca(int x, int y) {
	if(d[x] > d[y]) swap(x, y);
	
	for(int i = 19; i >= 0; i--) {
		if(d[fa[y][i]] >= d[x]) y = fa[y][i];
	}
	
	if(x == y) return x;
	
	for(int i = 19; i >= 0; i--) {
		if(fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
	}
	
	return fa[x][0];
}

int dfs(int p, int father) {
	int sum = val[p];
	
	for(int i = head[p]; i != -1; i = edge[i].next) {
		int now = edge[i].to;
		
		if(now == father) continue;
		
		int cnt = dfs(now, p);
		sum += cnt;
	}
	
	ff[p] = sum;
	return sum;
}

signed main() {
	while(scanf("%lld%lld", &n, &m) != EOF) {
		init();
		int u, v;
		
		for(int i = 1; i <= n - 1; i++) {
			scanf("%lld%lld", &u, &v);
			addedge(u, v);
			addedge(v, u);
		}
		
		bfs();
		
		for(int i = 1; i <= m; i++) {
			int a, b;
			cin >> a >> b;
			val[a]++;
			val[b]++;
			val[lca(a, b)] -= 2;
		}
		
		dfs(1, -1);
		ans = 0;
		
		for(int i = 2; i <= n; i++) {
			if(ff[i] == 1)
				ans++;
			else if(ff[i] == 0)
				ans += m;
		}
		
		cout << ans << endl;
	}
	
	return 0;
}
