#include <bits/stdc++.h>
using namespace std;
int w, n;
int main() {
	cin >> w >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	int L = 0, r = n-1, s = 0;
	while (L <= r) {
		if (a[L]+a[r] <= w) {
			L++; r--;
		}else r--;
		s++;
	}
	cout << s;
	return 0;
}