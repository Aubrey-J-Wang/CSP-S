#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;

vector<int> res_left, res_right, price;
int m, ans, n;

void dfs(int step, int now, vector<int>& res, int right_bound) { // Search forward.
	if (now > m) return; // Cut-branch

	if (step > right_bound) { // Stop at the half line.
		res.push_back(now);
		return;
	}

	dfs(step + 1, now + price[step], res, right_bound); // Chosen
	dfs(step + 1, now, res, right_bound); // Not chosen.
}

signed main() {
	cin >> n >> m;
	
	int mid = (n+1)/2;
	price.push_back(1e9);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        price.push_back(x);
    }

	dfs(1, 0, res_left, mid); // First half: Result in res_left.
	dfs(mid+1, 0, res_right, n); // Second half: Result in res_right.

	sort(res_right.begin(), res_right.end());
	for (int i : res_left) // We use binary search to optimize.
		ans += upper_bound(res_right.begin(), res_right.end(), m - i) - res_right.begin();
//		Binary search: 20 times at most.

	cout << ans;
	return 0;
}