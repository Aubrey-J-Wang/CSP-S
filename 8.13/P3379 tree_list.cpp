#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 500010;
const int M = N * 2;

vector<int> gv[N];
int f[N], top[N], d[N], _size[N], son[N];
int n, m, s;

void dfs1(int x) {
	_size[x] = 1;
	d[x] = d[f[x]] + 1;
	
	for(int y : gv[x]) {
		if(y == f[x]) continue;
		
		f[y] = x;
		dfs1(y);
		_size[x] += _size[y];
		
		if(_size[son[x]] < _size[y])
			son[x] = y;
	}
}

void dfs2(int x) {
	if(x == son[f[x]])
		top[x] = top[f[x]];
	else
		top[x] = x;
		
	for(int y : gv[x]) {
		if(y == f[x]) continue;
		
		dfs2(y);
	}
}

int lca(int x, int y) {
	while(top[x] != top[y]) {
		if(d[top[x]] < d[top[y]])
			swap(x, y);
			
		x = f[top[x]];
	}
	
	return (d[x] < d[y] ? x : y);
}

signed main() {
	cin >> n >> m >> s;
	
	for(int i = 1; i <= n - 1; i++) {
		int x, y;
		scanf("%lld%lld", &x, &y);
		gv[x].push_back(y);
		gv[y].push_back(x);
	}
	
	dfs1(s);
	dfs2(s);
	
	for(int i = 1; i <= m; i++) {
		int x, y;
		scanf("%lld%lld", &x, &y);
		printf("%lld\n", lca(x, y));
	}
	
	return 0;
}
