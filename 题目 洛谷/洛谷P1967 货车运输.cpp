//洛谷P1967, 货车运输, NOIP2013 提高组 D1T3
#include <bits/stdc++.h>
#define MAXN 500010
using namespace std;

int n, m, tot, num;
int head[MAXN];
int fa[MAXN];
int f[MAXN][50], dis[MAXN][50];
int depth[MAXN], lg[MAXN], vis[MAXN];

struct edge_graph {
	int u, v, w;
}e1[MAXN];

struct edge_tree {
	int to, next, w;
}e2[MAXN];

void add(int x, int y, int w) {
	e2[++tot].to = y;
	e2[tot].w = w;
	e2[tot].next = head[x];
	head[x] = tot;
}

int find(int x) {
	while (x != fa[x]) x = fa[x] = fa[fa[x]];
	return x;
}

bool cmp(edge_graph x, edge_graph y) {
	return x.w > y.w;
}

void kruskal() {
	sort(e1 + 1, e1 + m + 1, cmp);
	
	int eu, ev;
	for (int i = 1; i <= m; i++) {
		eu = find(e1[i].u);
		ev = find(e1[i].v);
		if (eu == ev) continue;
		
		fa[eu] = ev;
		add(e1[i].u, e1[i].v, e1[i].w);
		add(e1[i].v, e1[i].u, e1[i].w);
		if (++num == n) return;
	}
}

void dfs(int x, int fath, int we) {
	vis[x] = 1;
	depth[x] = depth[fath] + 1;
	f[x][0] = fath;
	dis[x][0] = we;
	
	for (int i = 1; (1 << i) <= depth[x]; i++) {
		f[x][i] = f[f[x][i - 1]][i - 1];
		dis[x][i] = min(dis[x][i - 1], dis[f[x][i - 1]][i - 1]);
	}
	
	for (int i = head[x]; i; i = e2[i].next) {
		if (e2[i].to != fath) 
		   dfs(e2[i].to, x, e2[i].w);
	}
	
	return;
}

int lca(int x, int y) {
	if (find(x) != find(y)) return -1;
	
	int ans = 210000000;
	
	if (depth[x] < depth[y]) swap(x, y);
	
	while (depth[x] > depth[y]) {
		ans = min(ans, dis[x][lg[depth[x] - depth[y]] - 1]);
		x = f[x][lg[depth[x] - depth[y]] - 1];
	}
	
	if (x == y) return ans;
	
	for (int i = lg[depth[x]] - 1; i >= 0; i--) {
		if (f[x][i] != f[y][i]) {
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
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= m; i++) { 
		scanf("%d%d%d", &e1[i].u, &e1[i].v, &e1[i].w);
	}
	
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	
	kruskal();
	
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i, 0, 0);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
	}
	
	int q;
	scanf("%d", &q);
	
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", lca(x, y));
	}
	return 0;
} 
