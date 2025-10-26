#include <iostream>
#include <vector>
using namespace std;
const int mod = 998244353;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	long long dp[1 << 10][1 << 10][10] = {0};
//	For each dp[N][U][j], U restores how which letters have appeared bofore via a 10-bit number and j denotes
//	the last chosen type.

	for(int i = 1; i <= n; i++) {
		int type = s[i - 1] - 'A';

		for(int u = 0; u < (1 << 10); u++) {
			for(int j = 0; j < 10; j++) {
				dp[i][u][j] = dp[i - 1][u][j];
				if(type == j) { // If type j appears consecutively...
					dp[i][u][j] += dp[i - 1][u][j];
					dp[i][u][j] %= mod;
				}
			}
		}

		for(int v = 0; v < (1 << 10); v++) {
			if(v & (1 << type)) continue;
//			If this type of contest has already appeared, as we have already considered this type above,
//			we cannot participate in this type of contest anymore.
			for(int j = 0; j < 10; j++) { // A new segment of type j.
				dp[i][v | (1 << type)][type] += dp[i - 1][v][j];
				dp[i][v | (1 << type)][type] %= mod;
			}
		}

		dp[i][1 << type][type]++; // If this is the first contest, add it from 0 to 1.
		dp[i][1 << type][type] %= mod;
	}

	long long res = 0;
	for(int u = 0; u < 1024; u++) {
		for(int j = 0; j < 10; j++) {
			res += dp[n][u][j]; // All possible cases must be considered.
			res %= mod;
		}
	}
	cout << res;
	return 0;
}