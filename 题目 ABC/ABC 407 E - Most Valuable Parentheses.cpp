//ABC 407 E - Most Valuable Parentheses
//https://atcoder.jp/contests/abc407/tasks/abc407_e
//https://atcoder.jp/contests/abc407/editorial/13107
//

#include <iostream>
#include <vector>
#include <queue>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::priority_queue;
using std::greater;

typedef long long ll;

ll solve (const ll n, const vector<ll> &a) {
	ll ans = 0;

	priority_queue<ll, vector<ll> > que;
	
	for (ll i = 0; i < n; i++) {
		if (i == 0) {
			que.push(a[i*2-0]);
		} else {
			que.push(a[i*2-1]);
			que.push(a[i*2-0]);
		}

		ll v = que.top();
		que.pop();

		ans += v;
	}

	return ans;
}

int main (void) {
	int T;
	cin >> T;
	
	while (T--) {
		ll n;
		cin >> n;
		vector<ll> a(n*2);
		for (ll i = 0; i < n*2; i++) {
			cin >> a[i];
		}

		cout << solve(n, a) << "\n";
	}

	return 0;
}

