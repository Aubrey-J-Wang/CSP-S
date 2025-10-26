#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 105;

int dp[10005];
// dp[k] denotes the money that you have when you have $k now and will sell everything the next day.

int price[MAXN][MAXN];
// price[i][j] denotes the price of the i-th object on the j-th day.

int main() {
	int t, n, m;
	cin >> t >> n >> m;
	
	for(int i = 1; i <= t; ++i) {
		for(int j = 1; j <= n; ++j)
			cin >> price[i][j];
	}
	
	int ans = m;
	
	for(int i = 1; i < t; ++i) {
		memset(dp, ~0x3f, sizeof dp);
		dp[ans] = ans; // If you buy nothing.
		
		for(int j = 1; j <= n; ++j) {
//	With $k in your hand.
			for(int k = ans; k >= price[i][j]; --k)
				dp[k - price[i][j]] = max(dp[k - price[i][j]], dp[k] + price[i + 1][j] - price[i][j]);
		}
		
		int ma = 0; // Maximum.
		
		for(int j = 0; j <= ans; ++j)
			ma = max(ma, dp[j]);

		ans = ma;
	}
	
	cout << ans << endl;
	return 0;
}
