#include <bits/stdc++.h>
using namespace std;
#define MAXN 50
#define int long long

int n;
int a[MAXN];
int dp[MAXN][MAXN], rt[MAXN][MAXN];

void print(int l, int r) {
    if (l > r) return;
    printf("%lld ", rt[l][r]);
    print(l, rt[l][r] - 1);
    print(rt[l][r] + 1, r);
}

signed main() {
    scanf("%lld", &n);
    register int i, j, k, t;
    
	for (i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        dp[i][i] = a[i];
        dp[i][i - 1] = 1;
        rt[i][i] = i;
    }

    for (t = 1; t < n; ++t) {
        for (i = 1; i + t <= n; ++i) {
            j = i + t;
            dp[i][j] = dp[i][i]+dp[i + 1][j];
            rt[i][j] = i;
            for (k = i + 1; k < j; ++k) {
                if (dp[i][j] < dp[i][k - 1] * dp[k + 1][j] + dp[k][k]) {
                    dp[i][j] = dp[i][k - 1] * dp[k + 1][j] + dp[k][k];
                    rt[i][j] = k;
                }
            }
        }
    }

    printf("%lld\n", dp[1][n]);
    print(1, n);
    return 0;
}
