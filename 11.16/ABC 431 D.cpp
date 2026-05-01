#include <iostream>
#include <vector>
#define loop(i, n, m) for(int i = (n); (i) <= (m); i++)
#define rev_loop(i, n, m) for(int i = (n); (i) >= (m); i--)
#define int long long
using namespace std;

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -f;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x * f;
}

void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

int w[505], h[505], b[505], mx, ans;
vector<vector<int> > dp(505, vector<int>(200005, -1e17));

signed main() {
	int n = read();
	loop (i, 1, n) w[i] = read(), h[i] = read(), b[i] = read(), mx += w[i];
	mx /= 2, dp[0][0] = 0;
	
	loop (i, 1, n) loop (j, 0, mx) {
		if (j >= w[i] && dp[i - 1][j - w[i]] != -1e17)
			dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + h[i]);
		if (dp[i - 1][j] != -1e17)
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + b[i]);
	}
	
	loop (j, 0, mx)
		if (dp[n][j] != -1e17) ans = max(ans, dp[n][j]);
	
	write(ans);
	return 0;
}
