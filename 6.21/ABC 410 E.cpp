#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(){
	int n, h, m;
	cin >> n >> h >> m;
	int a[n+1], b[n+1];
	for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	
	int dp[n+1][m+1];
	memset(dp, -1, sizeof dp);
	dp[0][m] = h;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			dp[i][j] = max(dp[i][j], dp[i-1][j]-a[i]);
			if(j+b[i] <= m) dp[i][j] = max(dp[i][j], dp[i-1][j+b[i]]);
		}
	}
	
	int ans = 0;
	for(auto& row : dp){
		int maxn = -1e9;
		for(int i : row) maxn = max(maxn, i);
		if(maxn >= 0) ans++;
		else break;
	}
	cout << ans-1;
	return 0;
}
