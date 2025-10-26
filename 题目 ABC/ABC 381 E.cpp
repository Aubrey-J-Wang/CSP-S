#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < n; i++)

int main() {
	int N, Q;
	string s;
	cin >> N >> Q >> s;
	vector<int> ls, sh, rs;
	rep(i, N) {
		if(s[i] == '1') ls.push_back(i);
		else if(s[i] == '2') rs.push_back(i);
		else sh.push_back(i);
	}
	int sz1 = ls.size(), szs = sh.size();
	rep(i, Q) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		int low = -1, high = N, ans = 0;
		while(high - low > 1) {
			int m = (low + high) / 2;
			if(m == 0) {
				int j = upper_bound(sh.begin(), sh.end(), r) - lower_bound(sh.begin(), sh.end(), l);
				if(j) {
					ans = max(ans, m * 2 + 1);
					low = m;
				}
				else high = m;
			}
			else {
				int j = lower_bound(ls.begin(), ls.end(), l) - ls.begin();
				if(j + m - 1 >= sz1 || ls[j + m - 1] > r) high = m;
				else {
					int k = upper_bound(sh.begin(), sh.end(), ls[j + m - 1]) - sh.begin();
					if(k >= szs || sh[k] > r) high = m;
					else {
						int n = upper_bound(rs.begin(), rs.end(), r) - upper_bound(rs.begin(), rs.end(), sh[k]);
						if(n < m) high = m;
						else {
							ans = max(ans, m * 2 + 1);
							low = m;
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
}