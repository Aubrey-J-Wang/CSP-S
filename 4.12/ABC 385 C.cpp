#include <iostream>
#include <cstdio>
using namespace std;

int a[3005], dp[3005][3005]; // dp[i][j] : The maximum number of legitimate arrangement ending in place j with interval i.

int main() {
    ios::sync_with_stdio(false);
    
    int n, ans = 1;
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++) dp[i][j] = 1; // If we choose one building, that still counts, so initialize to 1.
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			if(a[j-i] == a[j]) dp[i][j] = dp[i][j-i] + 1;
// 			If the buildings we found with interval i at j has the same height, the arrangement (so far) is legitimate, so update.
			else dp[i][j] = 1; // Else, nothing to do of course.
			ans = max(ans, dp[i][j]); // Finally, find maximum.
		}
	}
	
	cout << ans;
	return 0;
}
