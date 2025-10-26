#include <iostream>
#include <vector>
using namespace std;

int read();
void write(int x);

vector<int> a, dp, ans;
vector<vector<int>> g;

void dfs(int v, int p = -1) {
	dp[v] = a[v];
	
	for (auto to : g[v]) {
		if (to == p) continue;
		dfs(to, v);
		dp[v] += max(dp[to], 0);
	}
}

void dfs2(int v, int p = -1) {
	ans[v] = dp[v];
	
	for (int to : g[v]) {
		if (to == p) continue;
		
		dp[v] -= max(0, dp[to]);
		dp[to] += max(0, dp[v]);
		
		dfs2(to, v);
		
		dp[to] -= max(0, dp[v]);
		dp[v] += max(0, dp[to]);
	}
}

int main() {
	int n = read();
	
	a.resize(n), dp.resize(n), ans.resize(n);
	g = vector<vector<int>>(n);
	
	for (int i = 0; i < n; ++i) {
		a[i] = read();
		a[i] = (!a[i] ? -1 : a[i]);
	}
	
	for (int i = 1; i < n; ++i) {
		int x = read(), y = read();
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	dfs(0);
	dfs2(0);
	
	for (int it : ans) write(it), putchar(' ');
	return 0;
}



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
