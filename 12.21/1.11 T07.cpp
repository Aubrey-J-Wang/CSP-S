//1.11 T07 和为定数
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	long long n, i;
	cin >> n;
	long long a[n];

	for ( i = 0; i < n; i++) {
		cin >> a[i];
	}

	long long m;
	cin >> m;

	sort(a, a + n);

	i = 0;
	do {
		long long x = m - a[i];
		if (binary_search(a + i + 1, a + n, x)) {
			cout << a[i] << ' ' << x;
			return 0;
		}
		i++;
	} while (a[i] <= (m / 2));

	cout << "No";
	return 0;
}