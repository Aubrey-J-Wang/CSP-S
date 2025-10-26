#include <iostream>
using namespace std;

long long gcd(long long x, long long y) {
	if (x > y)
		swap(x, y);
	if (y % x == 0)
		return x;
	return gcd(y % x, x);
}

int main() {
	long long n, m, x, k;
	cin >> n >> m >> k;
	x = (n *m) / gcd(n, m);
	long long l = 0, r = (long long)2e+18, mid, y;
	while ((l + 1) < r) {
		mid = (l + r) / 2;
		y = (mid / n) + (mid / m) - 2 * (mid / x);
		if (y < k)
			l = mid;
		else
			r = mid;
	}
	cout << r << endl;
	return 0;
}
