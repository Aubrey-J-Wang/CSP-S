#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int i, n, j, x, m, L, r;
	cin >> n;
	int a[n + 1];
	for (i = 1; i <= n; i++)
		cin >> a[i];
//scanf(¡°%d¡±, &a[i]);
	sort(a + 1, a + n + 1);
	L = 1;
	r = n;
	cin >> x;
	while (L <= r) {
		m = (L + r) / 2;
		if (x == a[m]) {
			cout << "Found" << endl;
			return 0;
		}
		if (x < a[m])
			r = m - 1;
		else
			L = m + 1;
	} c
	out << "Not found" << endl;
	return 0;
}