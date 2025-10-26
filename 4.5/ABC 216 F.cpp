#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
const int mod = 998244353;

struct node {
	int a, b;
} c[N];

int n, f[N], ans;

bool cmp(node x, node y) {
	return x.a < y.a;
}

signed main() {
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++) cin >> c[i].a;
	for (int i = 1; i <= n; i++) cin >> c[i].b;

	sort(c + 1, c + n + 1, cmp);

	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= c[i].a - c[i].b; j++) (ans += f[j]) %= mod;
		for (int j = 5000; j >= c[i].b; j--) {
			(f[j] += f[j - c[i].b]) %= mod;
		}
	}

	cout << ans << endl;
	return 0;
}

