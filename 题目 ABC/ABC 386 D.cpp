#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, p = 1e18;

struct node {
	int h, l;
	char a;
} a[200005];

bool cmp(node x, node y) {
	if (x.h != y.h)
		return x.h < y.h;
	else
		return x.l < y.l;
}

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].h >> a[i].l >> a[i].a;
	}
	sort(a + 1, a + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		if (a[i].a == 'B') {
			if (a[i].l >= p) {
				cout << "No" << endl;
				return 0;
			}
		} else {
			p = min(p, a[i].l);
		}
	}
	cout << "Yes" << endl;
	return 0;
}
