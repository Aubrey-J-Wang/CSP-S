#include <iostream>
#include <vector>
#define mod 100000000
#define MAXN 12
using namespace std;

int dp[20][2005];
bool mark[2005][2005];
vector<int> state(2005, 0), map(20, 0);

bool impossible(int a) {
	bool flag = false;
	for (int i = 1; i <= MAXN; i++) {
		if (flag and a & 1) return true;
		flag = (a & 1);
		a >>= 1;
	}
	return false;
}

bool conflict(int a, int b) {
	for (int i = 1; i <= MAXN; i++) {
		if (a & 1 and b & 1) return true;
		a >>= 1, b >>= 1;
	}
	return false;
}

bool can_place(int a, int b) {
	return a | b == b;
}

int main() {
	int m, n;
	cin >> m >> n;

	for(int i = 0; i < (1 << MAXN); i++){
		if (not impossible(i)) state[++state[0]] = i;
	}
	for (int i = 1; i <= state[0]; i++){
		for (int j = i; j <= state[0]; j++){
			if (not conflict(state[i], state[j])) mark[i][j] = mark[j][i] = true;
		}
	}

	for (int i = 1; i <= m; i++) {
		int v = 0, t;
		for(int j = 1; j <= n; j++) cin >> t, v = v * 2 + t; // Binary to decimal.
		map[i] = v;
	}

//	"1" here denotes the state number for "00...0". It ensures that every first state for the first line to be "1" and
//  that we would get one way even if we choose none.
	dp[0][1] = 1;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= state[0]; j++)
			if (not can_place(state[j], map[i])) dp[i][j] = -1;
			else {
				for (k = 1; k <= state[0]; k++) {
					if (dp[i - 1][k] != -1 and mark[j][k]) dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
				}
			}

	int ans = 0;
	for (int j = 1; j <= state[0]; j++) {
		if (dp[m][j] != -1) ans = (ans + dp[m][j]) % mod;
	}
	cout << ans;
	return 0;
}