#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 100;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int &i : a)
		cin >> i;
	vector<vector<pair<int, int>>> qs(n);
	for (int i = 0; i < q; i++) {
		int r, x;
		cin >> r >> x;
		qs[--r].emplace_back(i, x);
	}
	vector<int> ans(q);
	vector<int> dp(n, inf);
	for (int i = 0; i < n; i++) {
		auto it = lower_bound(dp.begin(), dp.end(), a[i]);
		*it = a[i];
		for (auto [id, x] : qs[i]) {
			ans[id] = upper_bound(dp.begin(), dp.end(), x) - dp.begin();
		}
	}
	for (int i = 0; i < q; i++) {
		cout << ans[i] << '\n';
	}
}
