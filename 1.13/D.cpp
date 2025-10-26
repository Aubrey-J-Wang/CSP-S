#include <iostream>
#define int long long
using namespace std;

int a[500000+10], b[500000+10];

signed main() {
	ios::sync_with_stdio(false);
//	freopen("xxx.in", "r", stdin);
//  freopen("xxx.out", "w", stdout);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];

	int res = 0;
	for(int i = 1; i <= n; i++) {
		res += b[i];
		a[i] += res;
		int len = min(a[i], n-i);
		a[i] -= len;
		b[i+1]++, b[i+len+1]--;
	}

	for(int i = 1; i <= n; i++) cout << a[i] << ' ';
	return 0;
}