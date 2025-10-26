//ABC 410 E - Battles in a Row
//https://atcoder.jp/contests/abc410/tasks/abc410_e
//https://atcoder.jp/contests/abc410/editorial/13306
//https://atcoder.jp/contests/abc410/submissions/66912336

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3005;
int n, x, y, a[N], b[N], f[N], ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> x >> y;

	for (int i = 1; i <= n; i++) 
	    cin >> a[i] >> b[i];

	for (int i = 1, s = 0; i <= n; i++) {
		s += b[i];
		for (int j = N; j >= a[i]; j--) 
		   f[j] = max(f[j], f[j - a[i]] + b[i]);
		bool chk = 0;
		for (int j = 0; j <= x; j++)
			if (f[j] >= s - y) chk = 1;
		
		if (!chk) break;
		
		ans++;
	}
	
	cout << ans;
	return 0;
}


