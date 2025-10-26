#include <iostream>
const long long min_ll = LONG_LONG_MIN;

int n, m;
long long w[1005][1005], f[1005][1005][2];

inline long long mx(long long p, long long q, long long r) {
	return max(max(p, q), r);
}

inline long long dfs(int x, int y, int from) {
	if (x < 1 || x > n || y < 1 || y > m) return min_ll;

	if (f[x][y][from] != min_ll) return f[x][y][from];

	if (from == 0) f[x][y][from] = mx(dfs(x + 1, y, 0), dfs(x, y - 1, 0), dfs(x, y - 1, 1)) + w[x][y];
	else f[x][y][from] = mx(dfs(x - 1, y, 1), dfs(x, y - 1, 0), dfs(x, y - 1, 1)) + w[x][y];

	return f[x][y][from];
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			cin >> w[i][j];
			f[i][j][0] = f[i][j][1] = min_ll;
		}

	f[1][1][0] = f[1][1][1] = w[1][1];

	cout <<  dfs(n, m, 1);
	return 0;
}


