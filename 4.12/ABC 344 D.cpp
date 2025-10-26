#include <iostream>
#include <cstdio>
using namespace std;

// Let us consider a string 'correct' if this string is a continuous sub-string starting at place 1 of the string T.
// E.g. If T = "abcde", S = "abcd" is correct, while S = "bcd" is not.
int dp[105][105]; // dp[i][j] : The minimum money spent to get a string with the length of j (which is of course correct).

int main() {
    ios::sync_with_stdio(false);
    
    for(int &&i : dp) i = 1e9;
    
    dp[0][0] = 0;
    
    string t;
    cin >> t;
    int tl = t.length();
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){ // We 'stand' at place i to consider place i+1.
    	for(int j = 0; j < 105; j++) dp[j+1][j] = dp[i][j]; // If we choose nothing, dp will remain exactly the same.
    	
    	int m;
    	cin >> m;
    	while(m--){
    		string s;
    		cin >> s;
    		int sl = s.length();
    		for(int j = 0; j+sl <= tl; j++){ // Check whether this string will be correct if we put it at the end of S.
    			bool flag = true; // j is the starting place at which we start checking.
    			for(int k = 0; k < sl; k++){
    				if(t[j+k] != s[k]){ // We check the string after place j and if it fits, we can execute Line 41.
    					flag = false;
    					break;
					}
				}
// 				If the string is correct at place j, add the money by one and compare it to alternatives. (Find minimum)
				if(flag) dp[i+1][j+sl] = min(dp[i+1][j+sl], dp[i][j]+1); // Add the value respectively.
			}
		}
	}
	
	if(dp[n][tl] > 5e8) cout << -1;
	else cout << dp[n][tl];
	return 0;
}
