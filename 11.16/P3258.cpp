#include <iostream>
#include <vector>
#define loop(i, n, m) for(int i = (n); (i) < (m); i++)
#define rev_loop(i, n, m) for(int i = (n); (i) >= (m); i--)
using namespace std;

int read() {
	int x = 0, f = 1;
	char c = getchar();
	
	while(c < '0' || c > '9') {
		if(c == '-') f = -f;
		
		c = getchar();
	}
	
	while(c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	
	return x * f;
}

void write(int x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	
	if(x > 9) write(x / 10);
	
	putchar(x % 10 + '0');
}

struct ss {
	int next, to;
} info[600010];

int n, q;
int a[300010], head[600010];
int depth[300010], p[300010][25], sum[300010];

void add(int a, int b) {
	info[++q].to = b;
	info[q].next = head[a];
	head[a] = q;
}

void dfs(int a, int fa) {
	depth[a] = depth[fa] + 1;
	p[a][0] = fa;
	
	for(int i = 1; (1 << i) <= depth[a]; i++)
		p[a][i] = p[p[a][i - 1]][i - 1];
		
	for(int i = head[a]; i; i = info[i].next) {
		int v = info[i].to;
		
		if(v != fa) dfs(v, a);
	}
}

int lca(int a, int b) {
	if(depth[a] > depth[b]) swap(a, b);
	
	for(int i = 20; i >= 0; i--) {
		if(depth[a] <= depth[b] - (1 << i)) b = p[b][i];
	}

	if(a == b) return a;
	
	for(int i = 20; i >= 0; i--) {
		if(p[a][i] != p[b][i])
			a = p[a][i], b = p[b][i];
	}
	
	return p[a][0];
}

void search(int a) {
	for(int i = head[a]; i; i = info[i].next) {
		int v = info[i].to;
		
		if(v == p[a][0]) continue;
		
		search(v);
		sum[a] += sum[v];
	}
}

int main() {
	n = read();
	
	for(int i = 1; i <= n; i++)
		a[i] = read();
		
	for(int i = 1; i <= n - 1; i++) {
		int u = read(), v = read();
		add(u, v);
		add(v, u);
	}
	
	dfs(1, 0);
	
	for(int i = 1; i <= n - 1; i++) {
		int x = a[i], y = a[i + 1], LCA = lca(x, y);
		sum[x]++, sum[y]++;
		sum[LCA]--,	sum[p[LCA][0]]--;
	}
	
	search(1);
	
	for(int i = 2; i <= n; i++)
		sum[a[i]]--;
		
	for(int i = 1; i <= n; i++)
		write(sum[i]), putchar('\n');
		
	return 0;
}


