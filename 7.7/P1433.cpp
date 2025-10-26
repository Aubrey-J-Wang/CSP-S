/*
Years ago,
Washington cut down a cherry tree and confessed it to his father,
who forgave him.
However,
do you think it is really because he admitted his errors bravely?
Please do not forget,
that he still had the axe in his hand at that time.
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define int long long
#define double long double
using namespace std;

double x[20], y[20];
double dp[20][34000];
double distance[20][20];

double dis(int a, int b) {
	return sqrt((y[a] - y[b]) * (y[a] - y[b]) + (x[a] - x[b]) * (x[a] - x[b]));
}

signed main() {
	int n;
	cin >> n;
	memset(dp, 127, sizeof dp);
	int ans = dp[0][0];

	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	x[0] = y[0] = 0;

	for(int i = 0; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) distance[i][j] = distance[j][i] = dis(i, j);
	}

	for(int i = 1; i <= n; i++)	dp[i][1 << (i - 1)] = distance[0][i];

	for(int k = 1; k < (1 << n); k++) {
		for(int i = 1; i <= n; i++) {
			if(k & (1 << (i - 1)) == 0) continue;
			for(int j = 1; j <= n; j++) {
				if(j == i) continue;
				else if(k & (1 << (j - 1)) == 0) continue;
				dp[i][k] = min(dp[i][k], dp[j][k - (1 << (i - 1))] + distance[i][j]);
			}
		}
	}

	for(int i = 1; i <= n; i++) ans = min(ans, dp[i][(1 << n) - 1]);
	printf("%.2lf", ans);
	return 0;
}
