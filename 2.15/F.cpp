#include <iostream>
using namespace std;

#define int long long

int c[500005];

inline int lowbit(int x) {
	return (x) & (-x);
}

inline void update(int x, int v) {
	for (int i = x; i <= 300005; i += lowbit(i))
		c[i] += v;
}

inline int getsum(int x) {
	int s = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		s += c[i];

	return s;
}

signed main() {
	int n, cnt = 0;
	cin >> n;
	int a[n + 1];

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += 5;
	}

	for (int i = n; i >= 1; i--) { //k=0
		int now = a[i];
		cnt += getsum(now - 1);
		update(now, 1);
	}
	cout << cnt << '\n';

	for (int i = 1; i < n; i++) {
		cnt += n - 1 - (a[i] - 5); //7...., 9,...,8,....
		cnt -= (a[i] - 5);
		cout << cnt << '\n';
	}

}