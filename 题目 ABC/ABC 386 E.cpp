//ABC386 E

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<i64> a(n + 1);
	i64 flag = 0;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		flag ^= a[i];
	}

	if (k > n / 2) {
		k = n - k;
	} else {
		flag = 0;
	}

	vector<vector<i64>> val(k + 1);
	val[0].push_back(0);
	for (int i = 1; i <= n; i++) {
		for (int j = k - 1; j >= max(0, k - (n - i + 1)); j--) {
			for (auto x : val[j]) val[j + 1].push_back(x^a[i]);
		}
	}

	for (int i = 0; i < val[k].size(); i++) val[k][i] ^= flag;

	long long ans = 0;
	ans = max(ans, *max_element(val[k].begin(), val[k].end()));
	cout << ans;

	return 0;
}