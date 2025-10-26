#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<long long> a(n+1), b(n+1, 0);
    
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    for(int i = 1; i <= n; i++){ // b[i] : The productivity on the i-th workday after a series of holidays.
    	b[i] = b[i-1] + a[(i+1)/2]; // See editorial for reasons.
	}
	
	vector<vector<long long> > dp(n+1, vector<long long> (n+1, -4e18));
//	dp[i][j] = The maximum prodctvty (if j = 0, otherwise the original prodctvty) on the i-th day with j consecutive workdays
//  (including it).
	dp[1][0] = 0;
	
	for(int i = 1; i < n; i++){
		for(int j = 0; i <= n; j++){ // j : Number of consecutive workdays.
			if(dp[i][j] < 0) continue;
			dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]); // We calculate the prodctvty on holidays so never mind the workdays.
			dp[i+1][0] = max(dp[i+1][0], dp[i][j]+b[j]);
//		    The configuration of the first holiday after the group of holidays.(i.e. The original total prodctvty + the new one
//			that we have found now.
		}
	}
	
	long long res = 0;
	for(int i = 0; i < n; i++){
		res = max(res, dp[n][i]+b[i]); // Still thinking...
	}
	cout << res;
	return 0;
}
