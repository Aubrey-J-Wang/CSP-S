#include<iostream>
using namespace std;

int n;

struct edge {
	int next;
	int to;
} e[32010];

int cnt;
int head[16010];

void add_edge(int u, int v) {
	++cnt;
	e[cnt].next = head[u];
	e[cnt].to = v;
	head[u] = cnt;
}

int a[16010];
int f[16010];

void dfs(int u, int fa) {
	f[u] = a[u];
	
	for(int i = head[u]; i; i = e[i].next) {
		if(e[i].to == fa) continue;
		
		dfs(e[i].to, u);
		f[u] += max(0, f[e[i].to]);
	}
}

int main() {
	cin >> n;
	
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
		
	for(int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		add_edge(a, b);
		add_edge(b, a);
	}
	
	dfs(1, 0);
	int maxv = 0;
	
	for(int i = 1; i <= n; ++i)
		maxv = max(maxv, f[i]);
		
	cout << maxv << endl;
}
