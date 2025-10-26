
#include<bits/stdc++.h>
using namespace std;

long long a[1100005], b[1100005], s[55], ans, m, cntt, cnt, n;

void dfs1(int x, long long sum) {
	if(sum > m) return;

	if(x > n / 2) {
		a[++cnt] = sum;
		return;
	}

	dfs1(x + 1, sum + s[x]);
	dfs1(x + 1, sum);
}

void dfs2(int x, long long sum) {
	if(sum > m) return;

	if(x > n) {
		b[++cntt] = sum;
		return;
	}

	dfs2(x + 1, sum + s[x]);
	dfs2(x + 1, sum);
}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> s[i];

	dfs1(1, 0);
	dfs2(n / 2 + 1, 0);

	sort(a + 1, a + cnt + 1);
	sort(b + 1, b + cntt + 1);

	for(int i = 1; i <= cnt; i++)
		ans = max(ans, b[upper_bound(b + 1, b + cntt + 1, m - a[i]) - b - 1] + a[i]);

	cout << ans;
	return 0;
}
