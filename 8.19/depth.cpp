#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
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

int ans[1000005];

namespace custom{
	int size[1000005];
}
vector<int> g[1000005];

void dfs1(int p, int fa) {
	using custom::size;
	for(int i : g[p])
		if(i != fa)
			dfs1(i, p), size[p] += size[i];
			
	size[p]++, ans[p] = ans[fa] + 1;
}

void dfs2(int p, int fa) {
	using custom::size;
	for(int i : g[p])
		if(i != fa)
			ans[i] = n - 2*size[i] + ans[p], dfs2(i, p);
}

signed main() {
	int n = read();
	
	while(n--){
		int u = read(), v = read();
		g[u].emplace_back(v), g[v].emplace_back(u);
	}
		
	dfs1(1, 0), dfs2(1, 0);
	write(max_element(ans + 1, ans + n + 1) - ans);
	return 0;
}

