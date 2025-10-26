#include <iostream>
using namespace std;

int dp[505][505];

int main() {
	int n, ans = 0;
	cin >> n;
	
	for(int i = 1; i <= n; ++i) {
		cin >> dp[i][i];
		ans = max(ans, dp[i][i]);
	}
	
	for(int len = 2; len <= n; ++len) {
		for(int l = 1, r = len; r <= n; ++l, ++r) {
//			两个合并 Unite the twos.
			for(int k = l; k < r; ++k) {
				if(dp[l][k] and dp[k + 1][r] and dp[l][k] == dp[k + 1][r]) {
					dp[l][r] = dp[l][k] + dp[k + 1][r];
					break;
				}
			}
			
//			双指针，三个合并 Unite the threes with two pointers.
			for(int k = l, t = r; k < t - 1;) {
				if(dp[l][r]) break;
				
				if(!dp[l][k]) ++k;
				else if(!dp[t][r]) --t;
				else if(dp[l][k] == dp[t][r]) {
					if(dp[k + 1][t - 1])
						dp[l][r] = dp[l][k] + dp[k + 1][t - 1] + dp[t][r];
					else ++k, --t;
				} else if(dp[l][k] < dp[t][r]) ++k;
				else if(dp[l][k] > dp[t][r]) --t;
			}
			
			ans = max(ans, dp[l][r]);
		}
	}
	
	cout << ans;
	return 0;
}
