#include <iostream>
#include <queue>
#include <utility>
#define int long long
using namespace std;

signed main() {
	int Q;
	cin >> Q;
	queue<pair<int, int>> q;
	while(Q--) {
		int type;
		cin >> type;
		if(type == 1) {
			int c, x;
			cin >> c >> x;
			q.push({x, c});
		} else {
			int k;
			cin >> k;
			int ans = 0;
			while(k > q.front().second) {
				k -= q.front().second;
				ans += q.front().first * q.front().second;
				q.pop();
			}
			if(q.front().second >= k) {
				ans += q.front().first * k;
				if(q.front().second == k) q.pop();
				else q.front().second -= k;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
