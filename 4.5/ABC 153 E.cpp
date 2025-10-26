#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20001;
int h, n, dp[MAXN];

int main() {
	memset(f, 0x3f, sizeof dp);
	dp[0] = 0;
	cin >> h >> n;

	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = 0; j + a <= 20000; j++)
			dp[j + a] = min(dp[j + a], dp[j] + b);
	}

	cout << *min_element(&f[h], &f[20000] + 1);
	return 0;
}