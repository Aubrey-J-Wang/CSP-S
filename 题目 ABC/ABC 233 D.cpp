/*
   ABC 233 D - Count Interval
   https://atcoder.jp/contests/abc233/tasks/abc233_d
   https://atcoder.jp/contests/abc233/editorial/3186
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, l, r) for(ll i = l; i <= r; i++)

signed main() {
	ll n, k;
	cin >> n >> k;

	vector<ll> a(n);
	rep(i, 0, n - 1) cin >> a[i];

	vector<ll> s(n + 1);

	rep(i, 0, n - 1) s[i + 1] = s[i] + a[i];

	map<ll, ll> mp;
	ll ans = 0;

	rep(r, 1, n) {
		mp[s[r - 1]]++;
		ans += mp[s[r] - k];
	}

	cout << ans << endl;
	return 0;
}