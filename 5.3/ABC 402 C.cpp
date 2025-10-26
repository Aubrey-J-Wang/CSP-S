#include <vector>
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(m);
	vector<vector<int>> idx(n); // idx[i] : Array of dishes which uses the ingredient i.
	vector<int> cnt(m); // cnt[i] : Number of ingredients in the i-th dish that Snuke still had not overcome.
	
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		cnt[i] = k;
		a[i].resize(k);
		for (auto &e : a[i]) {
			cin >> e, e--; // As we start counting by 0 we have to decrease the input value by 1.
			idx[e].push_back(i);
		}
	}
	
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int b;
		cin >> b;
		b--;
		for (auto id : idx[b]) {
			cnt[id]--; // Snuke overcome an ingredient in every dish listed in idx[b].
			if (cnt[id] == 0) // If cnt[i] = 0, naturally this dish can be eaten by Snuke (now).
				ans++;
		}
		cout << ans << endl;
	}
//	In this way, the time complexity required to solve this porblem is O( N + M + SUM(K[i]) ).
	return 0;
}
