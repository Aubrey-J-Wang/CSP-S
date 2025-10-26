#include <iostream>
#include <algorithm>
using namespace std;

#define int long long

int a[200005];

signed main() {
	int n, k, x, ans = 0;
	cin >> n >> k >> x;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (!a[i])
			continue;
		int tmp = a[i] / x;
		if (tmp > k)
			tmp = k;
		a[i] -= x * tmp;
		k -= tmp;
fuqian:
		ans += a[i];
	}

	if (k) {
		sort(a + 1, a + n + 1, greater<int>());
		for (int i = 1; i <= min(n, k); i++)
			ans -= a[i];
	}

	ans = max(ans, 0ll);
	cout << ans;
}

