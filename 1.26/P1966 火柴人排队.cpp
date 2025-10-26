#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;
const int MOD = 99999997;

int n;
pii a[MAXN], b[MAXN];
int id[MAXN];
ll ans;

namespace BIT {
	int c[MAXN];

	int lowbit(int x) {
		return x & -x;
	}

	void Add(int x, int val) {
		while (x <= n) {
			c[x] += val;
			c[x] %= MOD;
			x += lowbit(x);
		}
	}

	int Query(int x) {
		int res = 0;
		while (x >= 1) {
			res += c[x];
			res %= MOD;
			x -= lowbit(x);
		}
		return res;
	}
}

bool cmp(pair<int, int> x, pair<int, int> y) {
	return x.first < y.first;
}

int main() {
	ios::sync_with_stdio(false);
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}

	for (int i = 1; i <= n; i++) {
		cin >> b[i].first;
		b[i].second = i;
	}

	sort(a + 1, a + 1 + n, cmp);
	sort(b + 1, b + 1 + n, cmp);

	for (int i = 1; i <= n; i++) id[b[i].second] = a[i].second;
	
	//A: 1   3   4   2     1    2   3   4
	//   1#  2#  3#  4#    1#   4#  2#  3#

	//B: 1   7   2   4     1    2   4   7
	//   1#  2#  3#  4#    1#   3#  4#  2#

	for (int i = 1; i <= n; i++) {
		BIT::Add(id[i], 1);
		ans += (i - BIT::Query(id[i]));
		ans %= MOD;
	}

	cout << ans;
	return 0;
}
