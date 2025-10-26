#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m, i, l, r;
	ios::sync_with_stdio(false);
	cin >> n;
	int a[n];
	for (i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	for (i = 0; i < m; i++) {
		int x;
		cin >> x; //10
		if (x <= a[0])
			cout << a[0] << endl;
		else if ( x >= a[n - 1])
			cout << a[n - 1] << endl;
		else {
			int *p;
			p = lower_bound(a, a + n, x);
			r = *p;
			l = *(p - 1);
			if ((x - l) <= (r - x) )
				cout << l << endl;
			else
				cout << r << endl;
		}
	}
	return 0;
}