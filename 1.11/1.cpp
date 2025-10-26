#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
//	freopen("xxx.in", "r", stdin);
//  freopen("xxx.out", "w", stdout);

	unsigned n;
	cin >> n;
	vector<unsigned> a(n), fa(n);
	for (auto &&i : a)
		cin >> i;

	for (unsigned i = 1; i < n; i++) {
		if (i % 2 == 0)
			fa[i] = fa[i - 1] + a[i] - a[i - 1];
		else
			fa[i] = fa[i - 1];
	}

	unsigned q;
	cin >> q;
	auto f{
		[&a, &fa](auto x) -> unsigned{
			const auto j = upper_bound(begin(a) + 1, end(a), x) - begin(a) - 1;
			return fa[j] + (fa[j + 1] - fa[j]) / (a[j + 1] - a[j]) * (x - a[j]);
		}
	};

	for (unsigned i = 0; i < q; i++) {
		unsigned l, r;
		cin >> l >> r;
		cout << f(r) - f(l) << endl;
	}

	return 0;
}
