//ABC 365 E - Xor Sigma Problem
//https://atcoder.jp/contests/abc365/tasks/abc365_e
//
//https://atcoder.jp/contests/abc365/submissions/56351320

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 2e5 + 10;
int n, a[N], ans, vis[2];

signed main() {
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		ans -= a[i];
	}
	
	for(int i = 0; i < 30; i++) {
		int now = 0;
		vis[0] = 1;
		vis[1] = 0;
		for(int j = 1; j <= n; j++) {
			now ^= (a[j] >> i) & 1;
			vis[now]++;
		}
		ans += vis[0] * vis[1] << i;
	}
	
	cout << ans << "\n";

	return 0;
}


