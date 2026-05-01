#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, m, s, cnt;

namespace custom{
	int size[1000005];
}

struct edge {
	int to, next;
} e[1000005];

int d[1000005], head[1000005], son[1000005], top[1000005], f[1000005], rk[1000005];

void add(int u, int v) {
	e[++cnt].next = head[u];
	e[cnt].to = v;
	head[u] = cnt;
}

void dfs1(int x) {
	using custom::size;
	size[x] = 1, d[x] = d[f[x]] + 1;
	
	for(int v, i = head[x]; i; i = e[i].next) {
		if((v = e[i].to) != f[x]) {
			f[v] = x, dfs1(v), size[x] += size[v];
			
			if(size[son[x]] < size[v])
				son[x] = v;
		}
	}
}

void dfs2(int x, int tp) {
	top[x] = tp;
	
	if(son[x])
		dfs2(son[x], tp);
		
	for(int v, i = head[x]; i; i = e[i].next) {
		if((v = e[i].to) != f[x] && v != son[x])
			dfs2(v, v);
	}
}

int lca(int x, int y) {
	while(top[x] != top[y]) {
		if(d[top[x]] < d[top[y]])
			swap(x, y);
			
		x = f[top[x]];
	}
	
	if(d[x] > d[y])
		swap(x, y);
		
	return x;
}

signed main() {
	cin >> n >> m >> s;
	
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}
	
	dfs1(s);
	dfs2(s, s);
	
	for(int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		cout << lca(x, y);
	}
	
	return 0;
}
