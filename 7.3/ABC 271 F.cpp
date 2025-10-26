#include <bits/stdc++.h>
using namespace std;

const int N = 25;
int n, a[N][N];
map<int, int> mp[20];
long long ans;

void dfs1(int x, int y, int c) {
	if(x + y == n + 1) {
		mp[x - 1][c]++;
		return;
	}

	dfs1(x + 1, y, c ^ a[x + 1][y]);
	dfs1(x, y + 1, c ^ a[x][y + 1]);
}

void dfs2(int x, int y, int c) {
	if(x + y == n + 2) {
		if(mp[x - 1].find(c) != mp[x - 1].end())
			ans += mp[x - 1][c];
		if(mp[x - 2].find(c) != mp[x - 2].end())
			ans += mp[x - 2][c];

		return;
	}

	dfs2(x - 1, y, c ^ a[x - 1][y]);
	dfs2(x, y - 1, c ^ a[x][y - 1]);
}

int main() {
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	dfs1(1, 1, a[1][1]);
	dfs2(n, n, 0 ^ a[n][n]);

	printf("%lld\n", ans);
}


