#include <iostream>
#define lowbit(x) ((x)&(-x))
using namespace std;

int a[500005], c[26][500005];

void update(int c[], int x, int v) {
	for (int i = x; i <= 500000; i += lowbit(i))
		c[i] += v;
}

int getsum(int c[], int x) {
	int sum = 0;

	for (int i = x; i >= 1; i -= lowbit(i))
		sum += c[i];

	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	
	int n, q;
	cin >> n;

	string a;
	cin >> a;
	a = '#' + a;

	for (int i = 1; i <= n; i++)
		update(c[a[i] - 'a'], i, 1);

	cin >> q;
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int l;
			string x;
			cin >> l >> x;
			char cc = x[0];
			update(c[a[l] - 'a'], l, -1);
			update(c[cc - 'a'], l, 1);
			a[l] = cc;
		}
		if (op == 2) {
			int l, r, ans = 0;
			cin >> l >> r;
			for (int i = 0; i < 26; i++)
				if (getsum(c[i], r) - getsum(c[i], l - 1))
					ans++;
			cout << ans << endl;
		}
	}
}

