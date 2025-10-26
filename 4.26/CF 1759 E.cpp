#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n, h;
		int p = 2, q = 1;
		cin >> n >> h;
		int a[n];
		for (int &i : a) cin >> i;
		sort(a, a + n);
		int maxn = -1;
		for (int k = 1; k <= 3; k++) {
			int cnt = 0;
			for (int i : a) {
				if (h > i) h += a[i] / 2, cnt++;
				else {
					if(k == 1 && p == 2 && q) h *= 3, q--;
					else if(k == 2 && p == 1 && q) h *= 3, q--;
					else if(k == 3 && p == 0) h *= 3, q--;
					else if(p) h *= 2, p--;
					else break;
				}
			}
			maxn = max(cnt, maxn);
		}
		cout << maxn << endl;
	}
	return 0;
}
