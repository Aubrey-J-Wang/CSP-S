//ABC 383 E - Sum of Max Matching
//https://atcoder.jp/contests/abc383/tasks/abc383_e
//
//https://atcoder.jp/contests/abc383/submissions/60606950

//
// Created by zml on 2024/12/9.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;

struct edge {
	int u, v, cost;
} e[N];

bool operator<(edge a, edge b) {
	return a.cost < b.cost;
}

int fa[N], val[N];
long long ans = 0;

int find(int x) {
	if (x != fa[x])
		fa[x] = find(fa[x]);
	return fa[x];
}

void mage(int x, int y, int cost) {
	int fax = find(x), fay = find(y);

	if (fax == fay)
		return;

	if (1ll * val[fax] * val[fay] < 0)
		ans += 1ll * cost * min(abs(val[fax]), abs(val[fay]));

	val[fax] += val[fay];
	fa[fay] = fax;
}

void solve() {
	int n, m, k, x;
	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++)
		cin >> e[i].u >> e[i].v >> e[i].cost;

	for (int i = 1; i <= n; i++)
		fa[i] = i;

	for (int i = 1; i <= k; i++)
		cin >> x, val[x]--;

	for (int i = 1; i <= k; i++)
		cin >> x, val[x]++;

	sort(e + 1, e + m + 1);

	for (int i = 1; i <= m; i++)
		mage(e[i].u, e[i].v, e[i].cost);

	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(20);
	int test = 1;
	while (test--) {
		solve();
	}
	return 0;
}