#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

signed main() {
	string s;
	ll k;
	cin >> s;
	cin >> k;
	ll n = s.size();

	vector<ll>  cnt(n + 1);

	for (ll i = 0; i <= n - 1; i++) {
		if (s[i] == '.')
			cnt[i + 1] = cnt[i] + 1;
		else
			cnt[i + 1] = cnt[i];
	}
	ll ans = 0, r = 0;

	for (ll l = 0; l <= n - 1; l++) {
		while (r <= n - 1 && cnt[r + 1] - cnt[l] <= k) r++;
		ans = max(ans, r-l);
	}

	cout << ans << endl;
	return 0;
}