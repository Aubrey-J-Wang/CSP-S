#include <iostream>
#include <cstdio>
using namespace std;

int dp[55][2510]; // dp[i][j] = The number of counts which satisfy that the length is i and sum of numbers is j.

int main() {
    ios::sync_with_stdio(false);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < k; j++){
    		for(int l = 1; l <= m; l++){
    			if(j+l <= k){
    				dp[i+1][j+l] = (dp[i+1][j+l] + dp[i][j]) % 998244353;
				}
			}
		}
	}
	
	long long ans = 0;
	for(int i = 1; i <= k; i++){ // Every sum less than k is good for us.
		ans += dp[n][i];
		ans %= 998244353;
	}
	
	cout << ans;
	return 0;
}
