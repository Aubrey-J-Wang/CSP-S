#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -f;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x * f;
}

void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

struct my {
	int v;
	int next;
	int w;
};

const int maxn = 500000 + 10;

int adj[maxn], fa, dp[maxn], root, du[maxn], f[maxn], ans;
my bian[maxn * 2];
bool vis[maxn];

void myinsert(int u, int v, int w) {
	bian[++fa].v = v;
	bian[fa].next = adj[u];
	adj[u] = fa;
	bian[fa].w = w;
}

void dfs1(int x) {
	vis[x] = true;
	
	for(int i = adj[x]; i; i = bian[i].next) {
		int v = bian[i].v;
		
		if(!vis[v]) {
			dfs1(v);
			
			if(du[v] != 1)
				dp[x] += min(bian[i].w, dp[v]);
			else
				dp[x] += bian[i].w;
		}
	}
}

void dfs2(int x) {
	vis[x] = true;
	
	for(int i = adj[x]; i; i = bian[i].next) {
		int v = bian[i].v;
		
		if(!vis[v]) {
			if(du[x] != 1)
				f[v] = dp[v] + min(f[x] - min(dp[v], bian[i].w), bian[i].w);
			else {
				f[v] = dp[v] + bian[i].w;
			}
			
			ans = max(f[v], ans);
			dfs2(v);
		}
	}
}

int main() {
	int t = read();
	
	while(t--) {
		fa = ans = 0;
		int n = read()
		
		for(int i = 1; i < n; i++) {
			int u = read(), v = read(), w = read();
			du[u]++, du[v]++;
			myinsert(u, v, w);
			myinsert(v, u, w);
		}
		
		root = 1;
		dfs1(root);
		memset(vis, 0, sizeof(vis));
		f[root] = dp[root];
		dfs2(root);
		write(ans);
		putchar('\n');
	}
	
	return 0;
}
