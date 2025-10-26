#include <iostream>
#include <vector>
#include <map>
#define int long long
using namespace std;

bool cmp(int x, int y) {
	return abs(x) < abs(y);
}

void solve() {
	for(int i = 2; i < n; i++) {
		if(a[i] * a[i] != a[i - 1] * a[i + 1]) {
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
}

signed main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for(int& i : a) cin >> i;
		sort(a.begin(), a.end());
		map<int, int> mp;
		for(int i : a) mp[i]++;

		if(mp.size() == 2 && mp[-a[1]] >= 1 && abs(mp[a[1]] - mp[-a[1]]) <= 1) cout << "Yes" << endl; // Special case.
		else solve();
	}
	return 0;
}
